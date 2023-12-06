#include "common/common.h"
#include "common/json.h"
#include "openssl.h"
#include "macho.h"
#include "bundle.h"
#include <libgen.h>
#include <dirent.h>
#include <getopt.h>

const struct option options[] = {
	{"debug", no_argument, NULL, 'd'},
	{"force", no_argument, NULL, 'f'},
	{"verbose", no_argument, NULL, 'v'},
	{"cert", required_argument, NULL, 'c'},
	{"pkey", required_argument, NULL, 'k'},
	{"prov", required_argument, NULL, 'm'},
	{"password", required_argument, NULL, 'p'},
	{"bundle_id", required_argument, NULL, 'b'},
	{"bundle_name", required_argument, NULL, 'n'},
	{"bundle_version", required_argument, NULL, 'r'},
	{"entitlements", required_argument, NULL, 'e'},
	{"output", required_argument, NULL, 'o'},
	{"zip_level", required_argument, NULL, 'z'},
	{"dylib", required_argument, NULL, 'l'},
	{"weak", no_argument, NULL, 'w'},
	{"install", no_argument, NULL, 'i'},
	{"quiet", no_argument, NULL, 'q'},
	{"help", no_argument, NULL, 'h'},
	{}};

extern "C" int zsign(char* appPath, char* p12Path, char* provPath, char* pass);

int zsign(char* appPath, char* p12Path, char* provPath, char* pass) {
	ZTimer gtimer;
	bool bForce = false;
	bool bInstall = false;
	bool bWeakInject = false;
	uint32_t uZipLevel = 0;
	string strCertFile;
	string strPKeyFile = p12Path;
	string strProvFile = provPath;
	string strPassword = pass;
	string strBundleId;
	string strBundleVersion;
	string strDyLibFile;
	string strOutputFile;
	string strDisplayName;
	string strEntitlementsFile;
	string strPath = appPath;
	if (!IsFileExists(strPath.c_str()))
	{
		ZLog::ErrorV(">>> Invalid Path! %s\n", strPath.c_str());
		return -1;
	}
	ZTimer timer;
	ZSignAsset zSignAsset;
	if (!zSignAsset.Init(strCertFile, strPKeyFile, strProvFile, strEntitlementsFile, strPassword)) {
	    return -1;
	}
	bool bEnableCache = true;
	string strFolder = strPath;
	timer.Reset();
	//ZAppBundle bundle;
	//bool bRet = bundle.SignFolder(&zSignAsset, strFolder, strBundleId, strBundleVersion, strDisplayName, strDyLibFile, bForce, bWeakInject, bEnableCache);
	//timer.PrintResult(bRet, ">>> Signed %s!", bRet ? "OK" : "Failed");
	gtimer.Print(">>> Done.");
	//return bRet ? 0 : -1;
	return 0;
}
