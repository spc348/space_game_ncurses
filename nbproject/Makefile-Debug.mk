#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Asteroid.o \
	${OBJECTDIR}/Collider.o \
	${OBJECTDIR}/Main.o \
	${OBJECTDIR}/Planet.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/Point.o \
	${OBJECTDIR}/SpaceObject.o \
	${OBJECTDIR}/Star.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs ncurses` `pkg-config --libs ncurses++` `pkg-config --libs ncurses++w`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Asteroid.o: Asteroid.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Asteroid.o Asteroid.cpp

${OBJECTDIR}/Collider.o: Collider.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Collider.o Collider.cpp

${OBJECTDIR}/Main.o: Main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Main.o Main.cpp

${OBJECTDIR}/Planet.o: Planet.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Planet.o Planet.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/Point.o: Point.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Point.o Point.cpp

${OBJECTDIR}/SpaceObject.o: SpaceObject.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SpaceObject.o SpaceObject.cpp

${OBJECTDIR}/Star.o: Star.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall `pkg-config --cflags ncurses` `pkg-config --cflags ncurses++` `pkg-config --cflags ncurses++w` -std=c++14  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Star.o Star.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
