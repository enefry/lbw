/* © 2010 David Given.
 * LBW is licensed under the MIT open source license. See the COPYING
 * file in this distribution for the full text.
 */

#ifndef DEVVFSNODE_H
#define DEVVFSNODE_H

#include "FakeVFSNode.h"

class PtsVFSNode;

class DevVFSNode : public FakeVFSNode
{
public:
	DevVFSNode(VFSNode* parent, const string& name);
	~DevVFSNode();

public:
	Ref<VFSNode> _ptsnode;
};

#endif
