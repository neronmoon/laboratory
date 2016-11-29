from subprocess import check_call
from os import environ
from functools import partial

projects = [
    'OOP/lab1',
]

cmake_generator = environ['CMAKE_GENERATOR']

for project in projects:
    print "############# Building %s #############" % project
    check_call('md arts/%s' % project, shell=True)
    call = partial(check_call, shell=True, cwd=project)
    call('cmake -G "%s" .' % cmake_generator)
    call('msbuild ALL_BUILD.vcxproj /verbosity:minimal /logger:"C:\Program Files\AppVeyor\BuildAgent\Appveyor.MSBuildLogger.dll"')
    call('dir')
    # call('Push-AppveyorArtifact mypackage.nupkg')
