// %BANNER_BEGIN%
// ---------------------------------------------------------------------
// %COPYRIGHT_BEGIN%
//
// Copyright (c) 2019 Magic Leap, Inc. All Rights Reserved.
// Use of this file is governed by the Creator Agreement, located
// here: https://id.magicleap.com/creator-terms
//
// %COPYRIGHT_END%
// ---------------------------------------------------------------------
// %BANNER_END%

#include <memory>

#include <sys/stat.h>

#include <ml_media_error.h>
#include <ml_lifecycle.h>
#include <ml_logging.h>

#include "Utility.h"

/*
    Helper class to get paths to directories accessible by the app
*/
class SelfInfo
{
public:
    SelfInfo() :
        _packageDirPath(),
        _writableDirPathLockedAndUnlocked(),
        _writableDirPath()
    {
        MLLifecycleSelfInfo* _info;
        MLResult result = MLLifecycleGetSelfInfo(&_info);
        if (result != MLResult_Ok || _info == nullptr)
        {
            ML_LOG(Error, "MLLifecycleGetSelfInfo() failed. Reason: %s.", MLMediaResultGetString(result));
            throw result;
        }

        _packageDirPath = std::string(_info->package_dir_path);
        _writableDirPathLockedAndUnlocked = std::string(_info->writable_dir_path_locked_and_unlocked);
        _writableDirPath = std::string(_info->writable_dir_path);

        MLLifecycleFreeSelfInfo(&_info);
        _info = nullptr;

        if (_packageDirPath.empty() ||
            _writableDirPathLockedAndUnlocked.empty() ||
            _writableDirPath.empty())
        {
            ML_LOG(Error, "MLLifecycleGetSelfInfo() returned invalid paths. Reason: %s.", MLMediaResultGetString(MLResult_UnspecifiedFailure));
            throw MLResult_UnspecifiedFailure;
        }
    }

    std::string PackageDirPath() const { return _packageDirPath; }
    std::string WritableDirPathLockedAndUnlocked() const { return _writableDirPathLockedAndUnlocked; }
    std::string WritableDirPath() const { return _writableDirPath; }

private:
    std::string _packageDirPath;
    std::string _writableDirPathLockedAndUnlocked;
    std::string _writableDirPath;
};

/*
    SearchMedia takes on a URI and checks it in the following order
    1) Is it an online path?
    2) Is it an absolute path?
    3) Is it in "<app path>/package/resources/<music file>"?
    4) Is it in "<app path>/documents/C1/<music file>"?
    5) Is it in "<app path>/documents/C2/<music file>"?
*/
std::string SearchMedia(std::string uri)
{
    std::unique_ptr<SelfInfo> selfInfo;
    std::string path;
    struct stat statInfo = {};

    // online path
    if (uri.substr(0, 7) == std::string("http://") ||
        uri.substr(0, 8) == std::string("https://") ||
        uri.substr(0, 7) == std::string("rtsp://"))
    {
        return uri;
    }

    // local media filepaths may optionally be prepended "file://"; just skip
    if (uri.substr(0, 7) == std::string("file://"))
    {
        uri = uri.substr(7);
    }

    //
    // try absolute path
    //      eg; "/documents/C2/echo-hereweare_2.mp4"

    path = uri;
    memset(&statInfo, 0, sizeof(struct stat));
    if (stat(path.c_str(), &statInfo) == 0 || S_ISREG(statInfo.st_mode))
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
        return path;
    }
    else
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" not found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
    }

    try
    {
        selfInfo.reset(new SelfInfo());
    }
    catch (const MLResult& result)
    {
        return std::string();
    }

    //
    // try  <selfInfo->package_dir_path>/resources/<path>
    //

    path = selfInfo->PackageDirPath();
    if (path.back() != '/')
    {
        path += "/";
    }
    path += std::string("resources/") + uri;

    memset(&statInfo, 0, sizeof(struct stat));
    if (stat(path.c_str(), &statInfo) == 0 || S_ISREG(statInfo.st_mode))
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
        return path;
    }
    else
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" not found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
    }

    //
    // try <selfInfo->writable_dir_path_locked_and_unlocked>/<path>
    //

    path = selfInfo->WritableDirPathLockedAndUnlocked();
    if (path.back() != '/')
    {
        path += "/";
    }
    path += uri;

    memset(&statInfo, 0, sizeof(struct stat));
    if (stat(path.c_str(), &statInfo) == 0 || S_ISREG(statInfo.st_mode))
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
        return path;
    }
    else
    {
        ML_LOG(Info, "%s() line: %d uri: \"%s\" not found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
    }

    //
    // try <selfInfo->writable_dir_path>/<path>
    //

    path = selfInfo->WritableDirPath();
    if (path.back() != '/')
    {
        path += "/";
    }
    path += uri;

    memset(&statInfo, 0, sizeof(struct stat));
    if (stat(path.c_str(), &statInfo) == 0 || S_ISREG(statInfo.st_mode))
    {
        ML_LOG(Info, "%s() line: %d file: \"%s\" found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
        return path;
    }
    else
    {
        ML_LOG(Info, "%s() line: %d file: \"%s\" not found: \"%s\"", __FUNCTION__, __LINE__, uri.c_str(), path.c_str());
    }

    // file not found in folders searched
    return std::string();
}
