#ifndef _REPOSITORY_H_
#define _REPOSITORY_H_

#include "Commit.hpp"
#include "Blob.hpp"
#include "StageArea.hpp"

#include <string>
#include <filesystem>
#include <unordered_set>

using std::string;
using std::filesystem::current_path;
using std::unordered_set;


class Repository {
public:
    /*
    .gitlite
        |--objects
        |   |--commit and blob
        |--refs
        |   |--heads
        |       |--main
        |--HEAD
        |--stage
    */
    static const string CWD;
    static const string GITLITE_DIR;
    static const string OBJECTS_DIR;
    static const string REFS_DIR;
    static const string HEADS_DIR;
    static const string HEAD;
    static const string STAGE;

    static void init();
    static void add(string fileName);
    static void remove(string fileName);
    static void commit(string msg);
    static void log();
    static void globalLog();
    static void find(string message);
    static void status();
    static void checkout(string file);
    static void checkout(string commitId, string file);
    static void checkoutBranch(string branchName);
    static void createBranch(string branchName);
    static void removeBranch(string branchName);
    static void reset(string commitId);
    static void merge(string branchName);
    static void checkIfInitialized();
    static Commit getCurCommit();
private:
    static void setCurBranch(string branchName);
    static void initCommit();
    static void addCommit(Commit commit);
    static Commit getHeadCommitByBranchName(string branchName);
    static Commit getCommitById(string id);
    static Blob getBlobById(string id);
    static void printCommit(Commit commit);
    static StageArea readStageArea();
    static void printBranches();
    static void printStagedFiles();
    static void printRemovedFiles();
    static void printModificationsNotStagedForCommit();
    static void printUntrackedFiles();
    static void printFileList(vector<string> fileList);
    static void changeCommitTo(string commitId);
    static Commit getCommonCommit(Commit a, Commit b);
    static unordered_set<string> getAllFiles(unordered_map<string, string> a, unordered_map<string, string> b, unordered_map<string, string> c);
    static string dealWithConflict(string file, string curBlobId, string givBlobId);
};

#endif
