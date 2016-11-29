from subprocess import check_call
from os import environ
from functools import partial
import glob

projects = {
    'lab1': 'OOP/lab1',
}

cmake_generator = environ['CMAKE_GENERATOR']

for name, path in projects.iteritems():
    print "############# Building %s #############" % name
    call = partial(check_call, shell=True, cwd=path)
    call('cmake -G "%s" .' % cmake_generator)
    call('msbuild ALL_BUILD.vcxproj /verbosity:minimal /logger:"C:\Program Files\AppVeyor\BuildAgent\Appveyor.MSBuildLogger.dll"')
    for artifact in glob('%s.*' % name):
        call('Push-AppveyorArtifact %s' % artifact)
