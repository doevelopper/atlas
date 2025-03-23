
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_GITREVISION_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_SEMVER_GITREVISION_HPP

/*
 * version.hpp
 *
 * Package information
 *
 *
 * Copyright (C) 2020 Wanhive Systems Private Limited (info@wanhive.com)
 * This program is part of the Wanhive IoT Platform.
 * Check the COPYING file for the license.
 *
 */

#define API_LIB_NAME_STR           "RULES_INFRA"
#define API_LIB_VERSION_STR        "0.0.1"
#define API_LIB_DESCRIPTION_STR    "Bazel Rules infra for my projects "
#define API_LIB_COPYRIGHT_STR      "(C) 2012 acme Ltd"
#define API_LIB_COPYRIGHT_FULL_STR "Copyright (C) 2012 acme Ltd"

#define API_LIB_PROJECT_STR         "Rule Infra"
#define API_LIB_PACKAGE_STR         "Bazel Rules Infra"
#define API_LIB_AUTHOR_STR          "AHL <rolland.doe@gmail.com>"
#define API_LIB_RELEASE_ISODATE_STR "2012-05-23T15:17:49+00:00"
#define API_LIB_RELEASE_YEAR_STR    "2012"
#define API_LIB_RELEASE_DATE_STR    "2012-05-23"
#define API_LIB_RELEASE_TIME_STR    "15:17:49"
#define API_LIB_FULL_REVISION_STR   "0.0.1"
#define API_LIB_REVISION_STR        "0.0.1"

#define API_LIB_RELEASE_YEAR       2012
#define API_LIB_RELEASE_EPOCH_TIME 1337786269
#define API_LIB_MAJOR_REVISION     1
#define API_LIB_MINOR_REVISION     6
#define API_LIB_PATCHLEVEL         1

#undef API_LIB_PRODUCT_NAME
#undef API_LIB_RELEASE_NAME
#undef API_LIB_RELEASE_AUTHOR
#undef API_LIB_LICENSE_TEXT

#define API_LIB_PRODUCT_NAME "Aurora Systems"
#define API_LIB_RELEASE_NAME ""
#define API_LIB_RELEASE_AUTHOR "Aurora Systems Private Limited"
#define API_LIB_LICENSE_TEXT "Apache-2.0 http://www.apache.org/licenses/LICENSE-2.0"

#undef API_LIB_RELEASE_VERSION
#undef API_LIB_RELEASE_YEAR
#undef API_LIB_RELEASE_EMAIL
#undef API_LIB_RELEASE_URL

#ifdef HAVE_CONFIG_H
#include <config.h>
#define API_LIB_RELEASE_VERSION PACKAGE_VERSION
#define API_LIB_RELEASE_YEAR INCEPTION_YEAR
#define API_LIB_RELEASE_EMAIL PACKAGE_BUGREPORT
#define API_LIB_RELEASE_URL PACKAGE_URL
#else
#define API_LIB_RELEASE_VERSION "VERSION"
#define API_LIB_RELEASE_YEAR "2018"
#define API_LIB_RELEASE_EMAIL "EMAIL"
#define API_LIB_RELEASE_URL "URL"
#endif
#endif
