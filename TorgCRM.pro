TEMPLATE = subdirs

SUBDIRS = CRMCommons \
        CRMBaseModule \
        Tests

CRMBaseModule.depends = CRMCommons

CONFIG += ordered

OTHER_FILES = LICENSE
