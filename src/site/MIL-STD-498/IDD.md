# Interface Design Description (IDD)

# 1.	Scope.
This section shall be divided into the following paragraphs.

## 1.1		Identification.
This paragraph shall contain a full identification of the system(s), the interfacing entities, and interfaces to which this document applies, including, as applicable, identification number(s), title(s), abbreviation(s), version number(s), and release number(s).

## 1.2		System overview.
This paragraph shall briefly state the purpose of the system(s) and software to which this document applies. It shall describe the general nature of the system and software; summarize the history of system development, operation, and maintenance; identify the project sponsor, acquirer, user, developer, and support agencies; identify current and planned operating sites; and list other relevant documents.

## 1.3		Document overview.
This paragraph shall summarize the purpose and contents of this document and shall describe any security or privacy considerations associated with its use.

# 2.	Referenced documents.
This section shall list the number, title, revision, and date of all documents referenced in this document. This section shall also identify the source for all documents not available through normal Government stocking activities.

# 3.	Interface design.
This section shall be divided into the following paragraphs to describe the interface characteristics of one or more systems, subsystems, configuration items, manual operations, or other system components. If part or all of the design depends upon system states or modes, this dependency shall be indicated. If design information falls into more than one paragraph, it may be presented once and referenced from the other paragraphs. If part or all of this information is documented elsewhere, it may be referenced. Design conventions needed to understand the design shall be presented or referenced.

## 3.1		Interface identification and diagrams.
For each interface identified in 1.1, this paragraph shall state the project-unique identifier assigned to the interface and shall identify the interfacing entities (systems, configuration items, users, etc.) by name, number, version, and documentation references, as applicable. The identification shall state which entities have fixed interface characteristics (and therefore impose interface requirements on interfacing entities) and which are being developed or modified (thus having interface requirements imposed on them). One or more interface diagrams shall be provided, as appropriate, to depict the interfaces.

## 3.x		(Project unique identifier of interface).
This paragraph (beginning with 3.2) shall identify an interface by project unique identifier, shall briefly identify the interfacing entities, and shall be divided into subparagraphs as needed to describe the interface characteristics of one or both of the interfacing entities. If a given interfacing entity is not covered by this IDD (for example, an external system) but its interface characteristics need to be mentioned to describe interfacing entities that are, these characteristics shall be stated as assumptions or as "When [the entity not covered] does this, [the entity that is covered] will ...." This paragraph may reference other documents (such as data dictionaries, standards for protocols, and standards for user interfaces) in place of stating the information here. The design description shall include the following, as applicable, presented in any order suited to the information to be provided, and shall note any differences in these characteristics from the point of view of the interfacing entities (such as different expectations about the size, frequency, or other characteristics of data elements):

1. Priority assigned to the interface by the interfacing entity(ies)
1. Type of interface (such as real-time data transfer, storage-and-retrieval of data, etc.) to be implemented
1. Characteristics of individual data elements that the interfacing entity(ies) will provide, store, send, access, receive, etc., such as:

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


1. Characteristics of data element assemblies (records, messages, files, arrays, displays, reports, etc.) that the interfacing entity(ies) will provide, store, send, access, receive, etc., such as:

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


1. Characteristics of communication methods that the interfacing entity(ies) will use for the interface, such as:

 1. Project-unique identifier(s)
1. Communication links/bands/frequencies/media and their characteristics
1. Message formatting
1. Flow control (such as sequence numbering and buffer allocation)
1. Data transfer rate, whether periodic/aperiodic, and interval between transfers
1. Routing, addressing, and naming conventions
1. Transmission services, including priority and grade
1. Safety/security/privacy considerations, such as encryption, user authentication, compartmentalization, and auditing


1. Characteristics of protocols the interfacing entity(ies) will use for the interface, such as:

 1. Project-unique identifier(s)
1. Priority/layer of the protocol
1. Packeting, including fragmentation and reassembly, routing, and addressing
1. Legality checks, error control, and recovery procedures
1. Synchronization, including connection establishment, maintenance, termination
1. Status, identification, and any other reporting features


1. Other characteristics, such as physical compatibility of the interfacing entity(ies) (dimensions, tolerances, loads, voltages, plug compatibility, etc.)



# 4.	Requirements traceability.
This paragraph shall contain:

1. Traceability from each interfacing entity covered by this IDD to the system or CSCI requirements addressed by the entity's interface design.
1. Traceability from each system or CSCI requirement that affects an interface covered in this IDD to the interfacing entities that address it.



# 5.	Notes.
This section shall contain any general information that aids in understanding this document (e.g., background information, glossary, rationale). This section shall include an alphabetical listing of all acronyms, abbreviations, and their meanings as used in this document and a list of any terms and definitions needed to understand this document.

# A.	Appendixes.
Appendixes may be used to provide information published separately for convenience in document maintenance (e.g., charts, classified data). As applicable, each appendix shall be referenced in the main body of the document where the data would normally have been provided. Appendixes may be bound as separate documents for ease in handling. Appendixes shall be lettered alphabetically (A, B, etc.).
