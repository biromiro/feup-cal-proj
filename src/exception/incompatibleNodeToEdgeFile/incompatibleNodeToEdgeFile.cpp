//
// Created by nrtc on 14/11/2020.
//

#include "incompatibleNodeToEdgeFile.h"


IncompatibleNodeToEdgeFile::IncompatibleNodeToEdgeFile(const std::string &nodePath, const std::string &edgePath,
                                                       const std::string &message) :
                                                       std::invalid_argument(message), nodePath(nodePath),
                                                       edgePath(edgePath){}

const std::string & IncompatibleNodeToEdgeFile::getNodePath() const {
    return nodePath;
}

const std::string &IncompatibleNodeToEdgeFile::getEdgePath() const {
    return edgePath;
}
