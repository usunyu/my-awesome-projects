# -*- tab-width: 4; indent-tabs-mode: nil -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
#

# This file (node.py) gets copied in several of my projects.  Find out a way
# to avoid making duplicate copies in each of my projects.

import sys

class NodeType:
    # unknown node type.
    Unknown = 0
    # the document root - typically has only one child element, but it can
    # have multiple children.
    Root    = 1
    # node that has name and attributes, and may have child nodes.
    Element = 2
    # node that only has textural content.
    Content = 3

class NodeBase:
    def __init__ (self, nodeType = NodeType.Unknown):
        self.parent = None
        self.nodeType = nodeType

        self.__children = []
        self.__hasContent = False

    def appendChild (self, node):
        self.__children.append(node)
        node.parent = self

    def appendElement (self, name):
        node = Element(name)
        self.appendChild(node)
        return node

    def hasContent (self):
        return self.__hasContent

    def appendContent (self, text):
        node = Content(text)
        self.appendChild(node)
        self.__hasContent = True
        return node

    def firstChild (self):
        return self.__children[0]

    def setChildNodes (self, children):
        self.__children = children

    def getChildNodes (self):
        return self.__children

    def firstChildByName (self, name):
        for child in self.__children:
            if child.nodeType == NodeType.Element and child.name == name:
                return child
        return None

    def getChildByName (self, name):
        children = []
        for child in self.__children:
            if child.nodeType == NodeType.Element and child.name == name:
                children.append(child)
        return children

class Root(NodeBase):
    def __init__ (self):
        NodeBase.__init__(self, NodeType.Root)

class Content(NodeBase):
    def __init__ (self, content):
        NodeBase.__init__(self, NodeType.Content)
        self.content = content

class Element(NodeBase):
    def __init__ (self, name, attrs=None):
        NodeBase.__init__(self, NodeType.Element)
        self.name = name
        self.attrs = attrs
        if self.attrs == None:
            self.attrs = {}

    def getContent (self):
        text = ''
        first = True
        for child in self.getChildNodes():
            if first:
                first = False
            else:
                text += ' '
            if child.nodeType == NodeType.Content:
                text += child.content
            elif child.nodeType == NodeType.Element:
                text += child.getContent()
        return text

    def getAttr (self, name):
        if not self.attrs.has_key(name):
            return None
        return self.attrs[name]

    def setAttr (self, name, val):
        self.attrs[name] = val

    def hasAttr (self, name):
        return self.attrs.has_key(name)

encodeTable = {
    '>': 'gt',
    '<': 'lt',
    '&': 'amp',
    '"': 'quot',
    '\'': 'apos'
}

# If utf8 is set, the input is either utf-8 bytes or Python
# Unicode. Output utf-8 instead of hex-dump.
def encodeString (sin, utf8 = False):
    sout = ''
    if utf8:
        if isinstance(sin, unicode):
            sout1 = sin.encode('UTF-8')
        else:
            sout1 = sin
        # Escape special characters as entities. Can't keep zero bytes either
        # (bad XML). They can only arrive here if there is a bug somewhere.
        for c in sout1:
            if ord(c) == 0:
                sout += '(nullbyte)'
            elif c in encodeTable:
                sout += '&' + encodeTable[c] + ';'
            else:
                sout += c
    else:
        for c in sin:
            if ord(c) >= 128 or ord(c) == 0:
                # encode non-ascii ranges.
                sout += "\\x%2.2x"%ord(c)
            elif encodeTable.has_key(c):
                # encode html symbols.
                sout += '&' + encodeTable[c] + ';'
            else:
                sout += c

    return sout

def convertAttrValue (val):
    if type(val) == type(True):
        if val:
            val = "true"
        else:
            val = "false"
    elif type(val) == type(0) or type(val) == type(0L):
        val = "%d"%val
    elif type(val) == type(0.0):
        val = "%g"%val

    return val

# If utf8 is set, the input is either utf-8 bytes or unicode
def prettyPrint (fd, node, utf8 = False):
    printNode(fd, node, 0, True, utf8 = utf8)

def printNode (fd, node, level, breakLine, utf8 = False):
    singleIndent = ''
    lf = ''
    if breakLine:
        singleIndent = ' '*4
        lf = "\n"
    indent = singleIndent*level
    if node.nodeType == NodeType.Root:
        # root node itself only contains child nodes.
        for child in node.getChildNodes():
            printNode(fd, child, level, True, utf8 = utf8)
    elif node.nodeType == NodeType.Element:
        hasChildren = len(node.getChildNodes()) > 0

        # We add '<' and '>' (or '/>') after the element content gets
        # encoded.
        line = node.name
        if len(node.attrs) > 0:
            keys = node.attrs.keys()
            keys.sort()
            for key in keys:
                val = node.attrs[key]
                if val == None:
                    continue
                val = convertAttrValue(val)
                line += " " + key + '="' + encodeString(val, utf8 = utf8) + '"'

        if hasChildren:
            breakChildren = breakLine and not node.hasContent()
            line = "<%s>"%line
            if breakChildren:
                line += "\n"
            fd.write (indent + line)
            for child in node.getChildNodes():
                printNode(fd, child, level+1, breakChildren, utf8 = utf8)
            line = "</%s>%s"%(node.name, lf)
            if breakChildren:
                line = indent + line
            fd.write (line)
        else:
            line = "<%s/>%s"%(line, lf)
            fd.write (indent + line)

    elif node.nodeType == NodeType.Content:
        content = node.content
        content = encodeString(content, utf8 = utf8)
        if len(content) > 0:
            fd.write (indent + content + lf)

# vim:set filetype=python shiftwidth=4 softtabstop=4 expandtab:
