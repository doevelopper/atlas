
* These helper macros generate a numerical and alphanumerical (see http://www.semver.org) representation of the library
* version number, i.e
*
*To address the limitations mentioned earlier, we'll need to expand the bit size from 32 bits to something larger,
*like 64 bits, to accommodate more significant versions and metadata. Here's a suggested table for mapping
*Semantic Versioning (SemVer) strings to 64-bit numerical values:

* | Component	        |  Bit Position	|    Range
* |-------------------------------------|-------------
* | Major Version	|    63-56	|    0x00-0xFF
* | Minor Version	|    55-48	|    0x00-0xFF
* | Patch Version	|    47-40	|    0x00-0xFF
* | Pre-release	        |    39-32	|    0x00-0xFF
* | Pre-release Count	|    31-24	|    0x00-0xFF
* | Build Metadata	|    23-16	|    0x00-0xFF
* | Build Count	        |    15-08	|    0x00-0xFF
* | Additional Flags	|    07-00	|    0x00-0xFF


# Semantic Versioning (SemVer) in 64-Bit Representation

This table illustrates how semantic versioning maps to 64-bit values using the bit layout defined in our Version class. 
Each component occupies a specific bit range to create a comprehensive versioning system.

| SemVer                                | 64-Bit Value              | Description                                                   |
|---------------------------------------|---------------------------|---------------------------------------------------------------|
| 0.0.1                                 | 0x0000010000000000        | Initial release                                               |
| 1.0.0                                 | 0x0100000000000000        | First stable release                                          |
| 1.2.3                                 | 0x0102030000000000        | Feature release with bug fixes                                |
| 2.0.0                                 | 0x0200000000000000        | Major release with breaking changes                           |
| 1.0.0-alpha                           | 0x0100000100000000        | Alpha pre-release (pre-release=1)                             |
| 1.0.0-alpha.1                         | 0x0100000101000000        | Alpha pre-release with iteration (pre-release count=1)        |
| 1.0.0-beta                            | 0x0100000200000000        | Beta pre-release (pre-release=2)                              |
| 1.0.0-beta.2                          | 0x0100000202000000        | Beta pre-release with iteration (pre-release count=2)         |
| 1.0.0-rc.1                            | 0x0100000301000000        | Release candidate (pre-release=3, pre-release count=1)        |
| 1.0.0+build.1                         | 0x0100000000010100        | Stable release with build metadata (build=1, build count=1)   |
| 1.0.0-beta.3+build.7                  | 0x0100000203010700        | Beta with build metadata                                      |
| 2.1.0-rc.3+build.5.revision.2         | 0x0201000303010500        | Complex version with additional flags (0x00 unused)           |
| 3.2.1-rc.4+1a3b.20220315              | 0x0302010304011A02        | Release candidate with date-stamped build (simplified)        |
| 4.0.0-beta.1+exp.sha.5114f85          | 0x0400000201010002        | Beta with experimental flag (0x02 in Additional Flags)        |
| 1.5.2+hotfix                          | 0x0105020000010000        | Stable release with hotfix indicator                          |
| 1.0.0-alpha+001                       | 0x0100000100010000        | Alpha with build sequence number                              |
| 5.10.3                                | 0x050A030000000000        | Major version 5 with double-digit minor                       |
| 1.0.0-alpha.beta                      | 0x0100000100000000        | Alpha pre-release (complex identifiers simplified)            |
| 2.3.0+jenkins.build.456               | 0x0203000000010400        | CI/CD build with build system indicator                       |
| 0.1.0-dev+sha.abc123                  | 0x0001000500010000        | Development pre-release (pre-release=5 for 'dev')             |
| 1.0.0-nightly.20220401                | 0x0100000600010000        | Nightly build (pre-release=6 for 'nightly')                   |
| 3.0.0+metadata                        | 0x0300000000010000        | Major release with simple metadata                            |
| 2.0.0-rc.1+build.123.branch.feature1  | 0x0200000301011200        | Release candidate from feature branch                         |
| 1.0.0-alpha.1.beta                    | 0x0100000101000000        | Complex pre-release (simplified to alpha.1)                   |
| 10.20.30                              | 0x0A141E0000000000        | Double-digit version components                               |
| 0.0.1-experimental                    | 0x0000010700000000        | Experimental version (pre-release=7 for 'experimental')       |
| 1.2.3-alpha+test.branch.fix           | 0x0102030100010000        | Alpha with test branch indicator                              |
| 9.9.9                                 | 0x0909090000000000        | Maximum single-digit component values                         |
| 255.255.255                           | 0xFFFFFF0000000000        | Maximum component values (0xFF for each 8-bit segment)        |

## Key for Pre-release Identifiers

Pre-release types are encoded in the Pre-release field (bits 39-32):

| Value | Pre-release Type |
|-------|------------------|
| 0     | None (stable)    |
| 1     | alpha            |
| 2     | beta             |
| 3     | rc               |
| 4     | preview          |
| 5     | dev              |
| 6     | nightly          |
| 7     | experimental     |
| 8-255 | custom           |

## Build Metadata Usage Guidelines

Build metadata (bits 23-16) can be used to indicate:

1. Build system identifier (1-10)
2. Build type (11-20)
3. Branch information (21-30)
4. Special flags (31-255)

## Additional Flags (bits 7-0) Recommendations

| Value | Flag Meaning                   |
|-------|--------------------------------|
| 0x00  | No flags                       |
| 0x01  | Debug build                    |
| 0x02  | Experimental features enabled  |
| 0x04  | Fast compilation               |
| 0x08  | Optimized build                |
| 0x10  | Compatibility mode             |
| 0x20  | Extended validation            |
| 0x40  | Deprecated                     |
| 0x80  | Security patch                 |

These flags can be combined using bitwise OR operations to represent multiple characteristics.