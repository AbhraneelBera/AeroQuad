#****************************************************************
#Usage :

#Source file in this directory will be automatocally compiled.

#To include any other directory use SRC_SEARCH_DIR += followed by 
#directory name (ending with / ).
#For example SRC_SEARCH_DIR += ~/Desktop/example/

#To include selective source files from other directories :
# For .c   files use C_SRC +=   followed by full path
# For .cpp files use CPP_SRC += followed by full path
# For .ino files use INO_SRC += followed by full path
# For .pde files use PDE_SRC += followed by full path

#Optional compile-time flags can be added using CFLAGS += or 
#CPPFLAGS += followed by flags.
#****************************************************************

CPPFLAGS += -Os
CPPFLAGS += -ffunction-sections
CPPFLAGS += -fdata-sections
CPPFLAGS += -funsigned-char
CPPFLAGS += -fsingle-precision-constant
#CPPFLAGS += -fshort-enums
CPPFLAGS += -fno-exceptions

SRC_SEARCH_DIR += ../../../AeroQuad/
SRC_SEARCH_DIR += ../../../AeroQuadBoneBlack/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Defines/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Receiver/
SRC_SEARCH_DIR += ../../../Libraries/AQ_RangeFinder/
SRC_SEARCH_DIR += ../../../Libraries/AQ_SoftModem/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Gyroscope/
SRC_SEARCH_DIR += ../../../Libraries/AQ_BatteryMonitor/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Kinematics/
SRC_SEARCH_DIR += ../../../Libraries/AQ_RSCode/
SRC_SEARCH_DIR += ../../../Libraries/AQ_RSSI/
SRC_SEARCH_DIR += ../../../Libraries/AQ_SPI/
SRC_SEARCH_DIR += ../../../Libraries/AQ_BarometricSensor/
SRC_SEARCH_DIR += ../../../Libraries/AQ_FlightControlProcessor/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Accelerometer/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Motors/
SRC_SEARCH_DIR += ../../../Libraries/AQ_I2C/
SRC_SEARCH_DIR += ../../../Libraries/AQ_OSD/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Math/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Gps/
SRC_SEARCH_DIR += ../../../Libraries/AQ_Compass/
SRC_SEARCH_DIR += ../../../Libraries/AQ_CameraStabilizer/

