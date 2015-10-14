#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED="WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.c" "WAFR-01-C001 HD-debug.X/user/user.c" "WAFR-01-C001 HD-debug.X/sys/system.c" "WAFR-01-C001 HD-debug.X/interrupts/interrupts.c" "WAFR-01-C001 HD-debug.X/EEprom/EEprom.c" "WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.c" "WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.c" "WAFR-01-C001 HD-debug.X/keyboard/keyboard.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED="${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1"
POSSIBLE_DEPFILES="${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1.d" "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1.d"

# Object Files
OBJECTFILES=${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/WAFR-01-C001-HD-debug\ main/WAFR-01-C001-HD-debug-main.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/user/user.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/sys/system.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/interrupts/interrupts.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/EEprom/EEprom.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/DS18B20/DS18B20.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1 ${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/keyboard/keyboard.p1

# Source Files
SOURCEFILES=WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.c WAFR-01-C001 HD-debug.X/user/user.c WAFR-01-C001 HD-debug.X/sys/system.c WAFR-01-C001 HD-debug.X/interrupts/interrupts.c WAFR-01-C001 HD-debug.X/EEprom/EEprom.c WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.c WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.c WAFR-01-C001 HD-debug.X/keyboard/keyboard.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F2420
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/WAFR-01-C001-HD-debug\ main/WAFR-01-C001-HD-debug-main.p1: WAFR-01-C001\ HD-debug.X/WAFR-01-C001-HD-debug\ main/WAFR-01-C001-HD-debug-main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1"  "WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/user/user.p1: WAFR-01-C001\ HD-debug.X/user/user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1"  "WAFR-01-C001 HD-debug.X/user/user.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/sys/system.p1: WAFR-01-C001\ HD-debug.X/sys/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1"  "WAFR-01-C001 HD-debug.X/sys/system.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/interrupts/interrupts.p1: WAFR-01-C001\ HD-debug.X/interrupts/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1"  "WAFR-01-C001 HD-debug.X/interrupts/interrupts.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/EEprom/EEprom.p1: WAFR-01-C001\ HD-debug.X/EEprom/EEprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1"  "WAFR-01-C001 HD-debug.X/EEprom/EEprom.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/DS18B20/DS18B20.p1: WAFR-01-C001\ HD-debug.X/DS18B20/DS18B20.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1"  "WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1: WAFR-01-C001\ HD-debug.X/RGBLedDisplay/RGBLedDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1"  "WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/keyboard/keyboard.p1: WAFR-01-C001\ HD-debug.X/keyboard/keyboard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1"  "WAFR-01-C001 HD-debug.X/keyboard/keyboard.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/WAFR-01-C001-HD-debug\ main/WAFR-01-C001-HD-debug-main.p1: WAFR-01-C001\ HD-debug.X/WAFR-01-C001-HD-debug\ main/WAFR-01-C001-HD-debug-main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1"  "WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/WAFR-01-C001-HD-debug main/WAFR-01-C001-HD-debug-main.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/user/user.p1: WAFR-01-C001\ HD-debug.X/user/user.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1"  "WAFR-01-C001 HD-debug.X/user/user.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/user/user.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/sys/system.p1: WAFR-01-C001\ HD-debug.X/sys/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1"  "WAFR-01-C001 HD-debug.X/sys/system.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/sys/system.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/interrupts/interrupts.p1: WAFR-01-C001\ HD-debug.X/interrupts/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1"  "WAFR-01-C001 HD-debug.X/interrupts/interrupts.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/interrupts/interrupts.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/EEprom/EEprom.p1: WAFR-01-C001\ HD-debug.X/EEprom/EEprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1"  "WAFR-01-C001 HD-debug.X/EEprom/EEprom.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/EEprom/EEprom.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/DS18B20/DS18B20.p1: WAFR-01-C001\ HD-debug.X/DS18B20/DS18B20.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1"  "WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/DS18B20/DS18B20.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1: WAFR-01-C001\ HD-debug.X/RGBLedDisplay/RGBLedDisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1"  "WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/RGBLedDisplay/RGBLedDisplay.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/WAFR-01-C001\ HD-debug.X/keyboard/keyboard.p1: WAFR-01-C001\ HD-debug.X/keyboard/keyboard.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard" 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d 
	@${RM} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1" 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o"${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1"  "WAFR-01-C001 HD-debug.X/keyboard/keyboard.c" 
	@-${MV} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard".d "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d 
	@${FIXDEPS} "${OBJECTDIR}/WAFR-01-C001 HD-debug.X/keyboard/keyboard.p1".d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=pickit3  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     --rom=default,-3dc0-3fff --ram=default,-2f4-2ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,+asmfile,-speed,+space,-debug --addrqual=ignore --mode=free -P -N255 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,+plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/WAFR-01-C001.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
