TEMPLATE = subdirs

SUBDIRS = CRMModels \
        CRMCommons \
        CRMBaseModule \
        Tests \

CRMBaseModule.depends = CRMCommons CRMModels
CRMCommons.depends = CRMModels

CONFIG += ordered
CONFIG += c++11

OTHER_FILES = LICENSE
