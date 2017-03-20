TEMPLATE = subdirs

CONFIG(debug, debug|release) {
    SUBDIRS += tests
}
