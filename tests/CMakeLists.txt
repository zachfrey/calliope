set(TEST_SOURCES
    mainwindow_smoke_test.cpp
    ../mainwindow.cpp
    ../mainwindow.h
    ../mainwindow.ui
)

add_executable(mainwindow_smoke_test
    ${TEST_SOURCES}
)

target_link_libraries(mainwindow_smoke_test PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
)

add_test(NAME mainwindow_smoke_test COMMAND mainwindow_smoke_test)
set_tests_properties(mainwindow_smoke_test PROPERTIES
    ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)
