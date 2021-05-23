//
// Created by nrtc on 14/11/2020.
//

#ifndef PROJECT_INVALIDAGE_H
#define PROJECT_INVALIDAGE_H

#include <iostream>
#include <exception>

/**
 * @file incompatibleNodeToEdgeFile.cpp
 *
 * @brief Exception for when the node path is incompatible with the edge path
 *
 * @ingroup exception
 */

class IncompatibleNodeToEdgeFile : public std::invalid_argument{
public:

    IncompatibleNodeToEdgeFile(const std::string& nodePath, const std::string& edgePath, const std::string &message);

    /**
     * Getter of the invalid node path
     *
     * @return invalid node path
     */
    const std::string &getNodePath() const;

    /**
    * Getter of the invalid edge path
    *
    * @return invalid edge path
    */
    const std::string &getEdgePath() const;

private:
    std::string nodePath;
    std::string edgePath;
};

#endif //PROJECT_INVALIDAGE_H
