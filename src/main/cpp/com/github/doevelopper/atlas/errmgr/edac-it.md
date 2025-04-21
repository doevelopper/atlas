You are an experienced C++20 software engineer specializing in embedded systems.
You always apply best coding practice.
You master SOLID principles,BDD, rule of fives ,all software design patterns and these framework: googletest, googlemock, Abseil-cpp,cucumber-cpp, Boost.statechart, Boost.program_options,Boost.Interprocess, Boost.CRC,Boost.Signals2,Boost.System,Boost.Asio.
Your task is to develop a comprehensive library for error management in an embedded system application.
The library should include the following components:

1. **Error Detection**: Implement mechanisms to identify errors promptly and accurately.
   2. **Error Classification**: Categorize errors based on their type, source, and severity.
   3. **Error Recovery Strategies**: Develop robust strategies to recover from errors, ensuring minimal disruption to system functionality.
   4. **Error Reporting**: Create detailed reporting mechanisms to log errors and provide insights for debugging and analysis. Reporting can consist in publishing error.
   5. **State Machine for State Transition**: Leverage Boost statechart framework to design a state machine to manage state transitions according to error severity, ensuring appropriate responses to different error conditions.
   6. **Extend Standard Error Categories**: Enhance the standard `error_category` with user-defined categories, including:
       - `generic_category`
       - `system_category`
       - `iostream_category`
       - `future_category`
       - `error_condition`
       - `error_code`

   7. **Modular Design:** Structure the library in a modular fashion to allow easy integration and extension. Each component (detection, classification, recovery, reporting, state machine)
      should be independently testable and maintainable.

   8. **Customizable Error Handling:** Provide interfaces for users to define custom error handling strategies tailored to specific application needs.
      This can include callback functions or hooks that execute custom recovery procedures.

   9. **Logging and Monitoring:** Integrate comprehensive logging and monitoring capabilities. Log4CXX framework can be leveraged.

   10. **Expand Reserved Fields:**
       Utilize the reserved fields for additional metadata or future extensions. This can help in maintaining backward compatibility while adding new features. see table description at the end

   11. **Error Descriptions:**
       Include a brief description for each error code. This can be helpful for debugging and understanding the nature of the error quickly.

   12. **Error Handling Policies:**
       Define policies for handling different error severities. For example, critical errors might trigger an immediate system reset, while informational errors could be logged for later review.
   13. **Error Context:
       Add context information to errors, such as the function name, file name, and line number where the error occurred. This can greatly aid in debugging.

   14. **Error Aggregation:**
       Implement mechanisms to aggregate similar errors to avoid flooding the system with redundant error messages. This can help in focusing on unique issues

Here are some additional informations to considere:

```plaintext
Exception class(for recoverable errors)
Error class (for unrecoverable errors)

Status Codes are 32 bit values formatted as follows:

Potential Improvements
Service Field Size: If your system grows to include more than 8 modules, 3 bits might feel limiting. 
You could reallocate bits from Mission Defined or Reserved, depending on your priorities.
Severity Granularity: Two bits are adequate for most cases, but if you need finer distinctions (e.g., 5+ severity levels), you’d need to adjust the bit allocation.
Class Row Clarification: The "Class" row in your table (e.g., "3 3 | 2 2 | ...") seems inconsistent with the bit counts (Sev is 2 bits, not 33). 
It might be a typo or an alternate notation. If it’s intentional, clarify its meaning; otherwise, align it with the 32Bits row for consistency.

   ___________________________________________________________________________________________________________________
 |        | Sev   |  Res  |   Serv   |      Mission  Defined      |                       Code                      |
 |:------:|:-----:|:-----:|:--------:|:--------------------------:|:-----------------------------------------------:|
 | Class  | 3  3  | 2  2  | 2  2  2  | 2  2  2  2  2  1  1  1  1  | 1  1  1  1  1  1  -  -  -  -  -  -  -  -  -  -  |
 | Index  | 1  0  | 9  8  | 7  6  5  | 4  3  2  1  0  9  8  7  6  | 5  4  3  2  1  0  9  8  7  6  5  4  3  2  1  0  |
 | 32Bits | 32 31 | 30 29 | 28 27 26 | 25 24 23 22 21 20 19 18 17 | 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 |

   _______________________________________________________________________________________
 |     |        ServiceID        |     |    |    Severity   |      |    |    Reserved   |
 |:---:|:-----------------------:|     |----|:-------------:|      |----|:-------------:|
 | 000 |    Not a CFE Service    |     | 00 |    Success    |      | 00 |    -------    |
 | 001 |    Events Services      |     | 01 | Informational |      | 01 |    -------    |
 | 010 |    Executive Services   |     | 10 |     Error     |      | 10 |    -------    |
 | 011 |    File Services        |     | 11 |    Critical   |      | 11 |    -------    |
 | 100 |    OS API Services      |
 | 101 |    Software Bus Services|
 | 110 |    Tables Services      |
 | 111 |    Time Services        |

 ________________________________________________________________________________________________________
 |           |                                      Mission,Defined                                     |
 |:---------:|:----------------------------------------------------------------------------------------:|
 | 000000000 | Used to classify error codes related to application specific library function calls, etc.|

 _______________________________________________________________________________________________________________
 |                  |                                      Error codes                                         |
 |:----------------:|:----------------------------------------------------------------------------------------:|
 | 0000000000000000 |                                    The status code.                                      |

``` 

```markdown
| Error Code | Description                                                                 | Example Code   |
|------------|-----------------------------------------------------------------------------|----------------|
| 0xyyyy1bbb | Normal failure (plausibly these should not even be "errors", but they are failures of the way operations are currently defined) | 0x00001bbb     |
| 0xyyyy15bb | Platform errors                                                             | 0x000015bb     |
| 0xyyyy2xxx | User attempt to do something illegal                                        | 0x00002xxx     |
| 2200       | Errors from bindings and official APIs                                      | 0x00002200     |
| 2300       | Backup and restore errors                                                   | 0x00002300     |
| 4xxx       | Internal errors (those that should be generated only by bugs)               | 0x00004xxx     |
| 5xxx       | Hardware-related errors                                                     | 0x00005xxx     |
| 6xxx       | Network-related errors                                                      | 0x00006xxx     |
| 7xxx       | Security-related errors                                                     | 0x00007xxx     |
| 8xxx       | Configuration errors                                                        | 0x00008xxx     |
| 9xxx       | Performance-related errors                                                  | 0x00009xxx     |
```

15. **User Documentation**: Provide comprehensive documentation for the error codes and their meanings. This can include a reference guide or an online help system.

According to all objects you will find relevent and that are involved in the framework achievement,
kindly give a full and well designed mermaid syntax of the folowwing request:

Structure Diagrams
Class Diagram
Component Diagram
Deployment Diagram
Object Diagram
Package Diagram
Profile Diagram
Composite Structure Diagram
Behavioral Diagrams
Use Case Diagram
Activity Diagram
State Machine Diagram
Sequence Diagram
Communication Diagram
Interaction Overview Diagram
Timing Diagram
