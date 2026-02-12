include(E:/TestProject/MinGwTest/build/Desktop_Qt_6_10_0_MinGW_64_bit-Release/.qt/QtDeploySupport-MinSizeRel.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/MinGwTest-plugins-MinSizeRel.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE E:/TestProject/MinGwTest/build/Desktop_Qt_6_10_0_MinGW_64_bit-Release/MinSizeRel/MinGwTest.exe
    GENERATE_QT_CONF
)
