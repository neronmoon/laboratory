from subprocess import check_call
from os import environ, listdir
from functools import partial

# project_folders = ['Algorithms', 'OOP', ]
project_folders = ['OOP', ]


for pf in project_folders:
    projects = map(
        lambda p: pf + '/' + p,
        filter(lambda d: d.startswith('lab'), listdir(pf))
    )
    for project in projects:
        print "############# Building %s #############" % project
        call = partial(check_call, shell=True, cwd=project)
        call('cmake -G "%s" .' % environ['CMAKE_GENERATOR'])
        call('msbuild ALL_BUILD.vcxproj /verbosity:minimal /logger:"C:\Program Files\AppVeyor\BuildAgent\Appveyor.MSBuildLogger.dll"')
        ar_name = project.replace('/', '_') + '.zip'
        for mask in ['*.doc', '*.docx', '*.h', '*.cpp', './Release/*.exe', '*.sln']:
            call('7z a %s %s' % (ar_name, mask))
        call('appveyor PushArtifact %s' % ar_name)
