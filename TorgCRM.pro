TEMPLATE = subdirs

SUBDIRS = CRMModels \
        CRMCommons \
        CRMBaseModule \
        Tests \

CRMBaseModule.depends = CRMCommons CRMModels
CRMCommons.depends = CRMModels

CONFIG += ordered

OTHER_FILES = LICENSE
