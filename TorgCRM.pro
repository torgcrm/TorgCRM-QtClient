TEMPLATE = subdirs

SUBDIRS = CRMCommons \
        CRMBaseModule \
        Tests

CRMBaseModule.depends = CRMCommons

CONFIG += ordered recursive

OTHER_FILES = LICENSE
