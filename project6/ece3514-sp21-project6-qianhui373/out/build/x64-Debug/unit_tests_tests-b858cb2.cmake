add_test( [==[Test basic interface]==] C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug/unit_tests.exe [==[Test basic interface]==])
set_tests_properties( [==[Test basic interface]==] PROPERTIES WORKING_DIRECTORY C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug)
add_test( [==[Test more]==] C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug/unit_tests.exe [==[Test more]==])
set_tests_properties( [==[Test more]==] PROPERTIES WORKING_DIRECTORY C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug)
add_test( [==[Test more row]==] C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug/unit_tests.exe [==[Test more row]==])
set_tests_properties( [==[Test more row]==] PROPERTIES WORKING_DIRECTORY C:/Users/project6/ece3514-sp21-project6-qianhui373/out/build/x64-Debug)
set( unit_tests_TESTS [==[Test basic interface]==] [==[Test more]==] [==[Test more row]==])
