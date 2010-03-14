/* © 2010 David Given.
 * LBW is licensed under the MIT open source license. See the COPYING
 * file in this distribution for the full text.
 */

#ifndef VFS_H
#define VFS_H

#include "VFSNode.h"

class VFS
{
public:
	static void SetRoot(const string& path);
	static Ref<VFSNode> GetRootNode();

	static void SetCWD(const string& path);
	static string GetCWD();
	static Ref<VFSNode> GetCWDNode();

	static void Resolve(VFSNode* cwd, const string& path, Ref<VFSNode>& node,
			string& leaf, bool followlink = true);

	static Ref<FD> OpenDirectory(VFSNode* cwd, const string& path,
			bool nofollow = false);
	static Ref<FD> OpenFile(VFSNode* cwd, const string& path,
			int flags = O_RDONLY, int mode = 0, bool nofollow = false);

	static void Stat(VFSNode* cwd, const string& path, struct stat& st);
	static void Lstat(VFSNode* cwd, const string& path, struct stat& st);
	static void MkDir(VFSNode* cwd, const string& path, int mode = 0);
	static void RmDir(VFSNode* cwd, const string& path);
	static string ReadLink(VFSNode* cwd, const string& path);
	static int Access(VFSNode* cwd, const string& path, int mode);
	static void Rename(VFSNode* cwd, const string& from, const string& to);
	static void Chmod(VFSNode* cwd, const string& path, int mode);
	static void Link(VFSNode* cwd, const string& from, const string& to);
	static void Unlink(VFSNode* cwd, const string& path);
	static void Symlink(VFSNode* cwd, const string& from, const string& to);
	static void Utime(VFSNode* cwd, const string& path, const struct utimbuf& ub);
};

#endif
