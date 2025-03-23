# MIL-STD-498

MIL-STD-498 can help you if you are a developer dealing with clients, but also if you're a project manager dealing with suppliers. I personally had used it in both situations.

By the end of this article, you'll be proficient enough in it to brag about it. And to know how to use it for various purposes when the need arises the next time.

# Index

## Plans

* [Software Development Plan (SDP)](<./01_Plans/SDP.md>)
* [Software Installation Plan (SIP)](<./01_Plans/SIP.md>)
* [Software Transition Plan (STrP)](<./01_Plans/STRP.md>)

## Concepts/Requirements

* [Operational Concept Description (OCD)](<./02_Requirements/OCD.md>)
* [System/Subsystem Specification (SSS)](<./02_Requirements/SSS.md>)
* [Software Requirements Specification (SRS)](<./02_Requirements/SRS.md>)
* [Interface Requirements Specification (IRS)](<./02_Requirements/IRS.md>)

## Design

* [System/Subsystem Design Description (SSDD)](<./03_Design/SSDD.md>)
* [Software Design Description (SDD)](<./03_Design/SDD.md>)
* [Database Design Description (DBDD)](<./03_Design/DBDD.md>)
* [Interface Design Description (IDD)](<./03_Design/IDD.md>)

## Qualification Test Products

* [Software Test Plan (STP)](<./04_Qualification/STP.md>)
* [Software Test Description (STD)](<./04_Qualification/STD.md>)
* [Software Test Report (STR)](<./04_Qualification/STR.md>)

## User/Operator Manuals

* [Software User Manual (SUM)](<./05_Operator_Manuals/SUM.md>)
* [Software Center Operator Manual (SCOM)](<./05_Operator_Manuals/SCOM.md>)
* [Software Input/Output Manual (SIOM)](<./05_Operator_Manuals/SIOM.md>)
* [Computer Operation Manual (COM)](<./05_Operator_Manuals/COM.md>)

## Support Manuals

* [Computer Programming Manual (CPM)](<./06_Support_Manuals/CPM.md>)
* [Firmware Support Manual (FSM)](<./06_Support_Manuals/FSM.md>)

## Software

* [Software Product Specification (SPS)](<./07_Software/SPS.md>)
* [Software Version Description (SVD)](<./07_Software/SVD.md>)

## 


The order they usually get written. Of course, certain projects might be different. Or you just need one template to document one aspect
## Phases 
### Request For Quotation phase
1. [Operational Concept Description (OCD)](<./02_Requirements/OCD.md>)
   This describes in the client's language what the project is about, what is wrong with the current situation, how will 
    the system improve it. If you're a developer, it's best used as a checklist for questioning the client about the project 
    details; if you're a project manager, use it as a template to write a very good description of your planned project for the suppliers.
2. [Software Development Plan (SDP)](<./01_Plans/SDP.md>)
   It just describes the very basics of how the development will happen: languages, tools, source control, trouble ticketing, 
   change management, testing, validation, phases, timetable, etc. It's best used as a checklist of things that should go into a contract.
3. [Software Installation Plan (SIP)](<./01_Plans/SIP.md>)
   It describes in general how and where the testing (especially the acceptance testing) will happen, without going into 
   details on individual tests. (Those come later in the unfortunately named STD document.)

### System design phase
1. [System/Subsystem Specification (SSS)](<./02_Requirements/SSS.md>) and [Software Requirements Specification (SRS)](<./02_Requirements/SRS.md>)
   There can be only one SSS, but if needed, there can be an SRS for each Subsystem. (I usually only do this sub-document thing if 
    the different subsystems are the responsibilities of different suppliers.) The SSS and SRS are basically the same and differ 
    only in minor wording -- in theory, the SSS might contain hardware descriptions too, while the SRS can only describe software.
2. [Interface Requirements Specification (IRS)](<./02_Requirements/IRS.md>)
   Only needed if the system will connect to one or more external systems. Best used as a checklist of what to collect from 
   (usually) third parties. (One can rarely dictate the format of third party documentation.)

### Development phase
1. [System/Subsystem Design Description (SSDD)](<./03_Design/SSDD.md>) , [Software Design Description (SDD)](<./03_Design/SDD.md>) 
   and [Interface Design Description (IDD)](<./03_Design/IDD.md>)
   These describe the evolving, and in the end the final design of the system and the subsystems and the interfaces. These are basically counterparts with the
   Specifications: 
    - [System/Subsystem Specification (SSS)](<./02_Requirements/SSS.md>) - [System/Subsystem Design Description (SSDD)](<./03_Design/SSDD.md>)
    - [Software Requirements Specification (SRS)](<./02_Requirements/SRS.md>) - [Software Design Description (SDD)](<./03_Design/SDD.md>)
    - [Interface Requirements Specification (IRS)](<./02_Requirements/IRS.md>) - [Interface Design Description (IDD)](<./03_Design/IDD.md>)
    
   The templates that end in "S" (as in Specification) are supposedly written (or at least, the information is given) by the 
    customer; while the ones ending in "DD" (as in "Design Description"), are written by the developer.

### Testing phase
1. [Software Test Report (STR)](<./04_Qualification/STR.md>)
   This is basically the output of doing the STDs according to the STP.

### Manuals
1. [Software User Manual (SUM)](<./05_Operator_Manuals/SUM.md>)
   Document by user functions, not by features.Can be omitted if there is no user interface.
2. [Software Center Operator Manual (SCOM)](<./05_Operator_Manuals/SCOM.md>)
   A template to document the operation of the system. It's to be done if someone else will do the hosting.
3. [Software Input/Output Manual (SIOM)](<./05_Operator_Manuals/SIOM.md>)
   It's best used as a template for documenting APIs. Omit if there is no API.

### Delivery phase
1. [Software Product Specification (SPS)](<./07_Software/SPS.md>)
   Best used as a checklist of things expected to be delivered.
2. [Software Version Description (SVD)](<./07_Software/SVD.md>)
   This is basically a "change log" template. Use when delivering changes to a system already in operation.

<!--
Application and Reference
SOFTWARE DEVELOPMENT AND DOCUMENTATION
-->