# Interface Requirements Specification (IRS)

# 1.	Scope.
This section shall be divided into the following paragraphs.

## 1.1	Identification.
This paragraph shall contain a full identification of the systems, the interfacing entities, and the interfaces to which this document applies, including, as applicable, identification number(s), title(s), abbreviation(s), version number(s), and release number(s).

## 1.2		System overview.
This paragraph shall briefly state the purpose of the system(s) and software to which this document applies. It shall describe the general nature of the system and software; summarize the history of system development, operation, and maintenance; identify the project sponsor, acquirer, user, developer, and support agencies; identify current and planned operating sites; and list other relevant documents.

## 1.3		Document overview.
This paragraph shall summarize the purpose and contents of this document and shall describe any security or privacy considerations associated with its use.

# 2.	Referenced documents.
This section shall list the number, title, revision, and date of all documents referenced in this specification. This section shall also identify the source for all documents not available through normal Government stocking activities.

# 3.	Requirements.
This section shall be divided into the following paragraphs to specify the requirements imposed on one or more systems, subsystems, configuration items, manual operations, or other system components to achieve one or more interfaces among these entities. Each requirement shall be assigned a project-unique identifier to support testing and traceability and shall be stated in such a way that an objective test can be defined for it. Each requirement shall be annotated with associated qualification method(s) (see section 4) and traceability to system (or subsystem, if applicable) requirements (see section 5.a) if not provided in those sections. The degree of detail to be provided shall be guided by the following rule: Include those characteristics of the interfacing entities that are conditions for their acceptance; defer to design descriptions those characteristics that the acquirer is willing to leave up to the developer. If a given requirement fits into more than one paragraph, it may be stated once and referenced from the other paragraphs. If an interfacing entity included in this specification will operate in states and/or modes having interface requirements different from other states and modes, each requirement or group of requirements for that entity shall be correlated to the states and modes. The correlation may be indicated by a table or other method in this paragraph, in an appendix referenced from this paragraph, or by annotation of the requirements in the paragraphs where they appear.

## 3.1		Interface identification and diagrams.
For each interface identified in 1.1, this paragraph shall include a project-unique identifier and shall designate the interfacing entities (systems, configuration items, users, etc.) by name, number, version, and documentation references, as applicable. The identification shall state which entities have fixed interface characteristics (and therefore impose interface requirements on interfacing entities) and which are being developed or modified (thus having interface requirements imposed on them). One or more interface diagrams shall be provided to depict the interfaces.

## 3.x		(Project unique identifier of interface).
This paragraph (beginning with 3.2) shall identify an interface by project unique identifier, shall briefly identify the interfacing entities, and shall be divided into subparagraphs as needed to state the requirements imposed on one or more
of the interfacing entities to achieve the interface. If the interface characteristics of an entity are not covered by this IRS but need to be mentioned to specify the requirements for entities that are, those characteristics shall be stated as assumptions or as "When [the entity not covered] does this, the [entity being specified] shall...," rather than as requirements on the entities not covered by this IRS. This paragraph may reference other documents (such as data dictionaries, standards for communication protocols, and standards for user interfaces) in place of stating the information here. The requirements shall include the following, as applicable, presented in any order suited to the requirements, and shall note any differences in these characteristics from the point of view of the interfacing entities (such as different expectations about the size, frequency, or other characteristics of data elements):

1. Priority that the interfacing entity(ies) must assign the interface
1. Requirements on the type of interface (such as real-time data transfer, storage-and-retrieval of data, etc.) to be implemented
1. Required characteristics of individual data elements that the interfacing entity(ies) must provide, store, send, access, receive, etc., such as:

 1. Names/identifiers

 1. Project-unique identifier
1. Non-technical (natural-language) name
1. DoD standard data element name
1. Technical name (e.g., variable or field name in code or database)
1. Abbreviation or synonymous names


1. Data type (alphanumeric, integer, etc.)
1. Size and format (such as length and punctuation of a character string)
1. Units of measurement (such as meters, dollars, nanoseconds)
1. Range or enumeration of possible values (such as 0-99)
1. Accuracy (how correct) and precision (number of significant digits)
1. Priority, timing, frequency, volume, sequencing, and other constraints, such as whether the data element may be updated and whether business rules apply
1. Security and privacy constraints
1. Sources (setting/sending entities) and recipients (using/receiving entities)


1. Required characteristics of data element assemblies (records, messages, files, arrays, displays, reports, etc.) that the interfacing entity(ies) must provide, store, send, access, receive, etc., such as:

 1. Names/identifiers

 1. Project-unique identifier
1. Non-technical (natural language) name
1. Technical name (e.g., record or data structure name in code or database)
1. Abbreviations or synonymous names


1. Data elements in the assembly and their structure (number, order, grouping)
1. Medium (such as disk) and structure of data elements/assemblies on the medium
1. Visual and auditory characteristics of displays and other outputs (such as colors, layouts, fonts, icons and other display elements, beeps, lights)
1. Relationships among assemblies, such as sorting/access characteristics
1. Priority, timing, frequency, volume, sequencing, and other constraints, such as whether the assembly may be updated and whether business rules apply
1. Security and privacy constraints
1. Sources (setting/sending entities) and recipients (using/receiving entities)


1. Required characteristics of communication methods that the interfacing entity(ies) must use for the interface, such as:

 1. Project-unique identifier(s)
1. Communication links/bands/frequencies/media and their characteristics
1. Message formatting
1. Flow control (such as sequence numbering and buffer allocation)
1. Data transfer rate, whether periodic/aperiodic, and interval between transfers
1. Routing, addressing, and naming conventions
1. Transmission services, including priority and grade
1. Safety/security/privacy considerations, such as encryption, user authentication, compartmentalization, and auditing


1. Required characteristics of protocols the interfacing entity(ies) must use for the interface, such as:

 1. Project-unique identifier(s)
1. Priority/layer of the protocol
1. Packeting, including fragmentation and reassembly, routing, and addressing
1. Legality checks, error control, and recovery procedures
1. Synchronization, including connection establishment, maintenance, termination
1. Status, identification, and any other reporting features


1. Other required characteristics, such as physical compatibility of the interfacing entities (dimensions, tolerances, loads, plug compatibility, etc.), voltages, etc.



## 3.y		Precedence and criticality of requirements.
This paragraph shall be numbered as the last paragraph in Section 3 and shall specify, if applicable, the order of precedence, criticality, or assigned weights indicating the relative importance of the requirements in this specification. Examples include identifying those requirements deemed critical to safety, to security, or to privacy for purposes of singling them out for special treatment. If all requirements have equal weight, this paragraph shall so state.

# 4.	Qualification provisions.
This section shall define a set of qualification methods and shall specify, for each requirement in Section 3, the qualification method(s) to be used to ensure that the requirement has been met. A table may be used to present this information, or each requirement in Section 3 may be annotated with the method(s) to be used. Qualification methods may include:

1. Demonstration: The operation of interfacing entities that relies on observable functional operation not requiring the use of instrumentation, special test equipment, or subsequent analysis.
1. Test: The operation of interfacing entities using instrumentation or special test equipment to collect data for later analysis.
1. Analysis: The processing of accumulated data obtained from other qualification methods. Examples are reduction, interpretation, or extrapolation of test results.
1. Inspection: The visual examination of interfacing entities, documentation, etc.
1. Special qualification methods: Any special qualification methods for the interfacing entities, such as special tools, techniques, procedures, facilities, and acceptance limits.



# 5.	Requirements traceability
For system-level interfacing entities, this paragraph does not apply. For each subsystem- or lower-level interfacing entity covered by this IRS, this paragraph shall contain:

1. Traceability from each requirement imposed on the entity in this specification to the system (or subsystem, if applicable) requirements it addresses. (Alternatively, this traceability may be provided by annotating each requirement in Section 3.)

 Note: Each level of system refinement may result in requirements not directly traceable to higher-level requirements. For example, a system architectural design that creates multiple CSCIs may result in requirements about how the CSCIs will interface, even though these interfaces are not covered in system requirements. Such requirements may be traced to a general requirement such as "system implementation" or to the system design decisions that resulted in their generation.

1. Traceability from each system (or subsystem, if applicable) requirement that has been allocated to the interfacing entity and that affects an interface covered in this specification to the requirements in this specification that address it.



# 6.	Notes.
This section shall contain any general information that aids in understanding this document (e.g., background information, glossary, rationale). This section shall include an alphabetical listing of all acronyms, abbreviations, and their meanings as used in this document and a list of any terms and definitions needed to understand this document.

# A.	Appendixes.
Appendixes may be used to provide information published separately for convenience in document maintenance (e.g., charts, classified data). As applicable, each appendix shall be referenced in the main body of the document where the data would normally have been provided. Appendixes may be bound as separate documents for ease in handling. Appendixes shall be lettered alphabetically (A, B, etc.).
