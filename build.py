from subprocess import check_call
from os import environ, listdir
from functools import partial

projects = map(
    lambda p: 'OOP/' + p,
    filter(lambda d: d.startswith('lab'), listdir('OOP'))
)

for project in projects:
    print "############# Building %s #############" % project
    call = partial(check_call, shell=True, cwd=project)
    call('cmake -G "%s" .' % environ['CMAKE_GENERATOR'])
    call('msbuild ALL_BUILD.vcxproj /verbosity:minimal /logger:"C:\Program Files\AppVeyor\BuildAgent\Appveyor.MSBuildLogger.dll"')
    ar_name = project.replace('/', '_') + '.zip'
    call('7z a %s *' % ar_name)
    call('appveyor PushArtifact %s' % ar_name)
