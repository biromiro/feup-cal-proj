//
// Created by Danny on 17/11/2020.
//

#include "nicknameNotFound.h"

#include <utility>

NicknameNotFound::NicknameNotFound(std::string nickname, const std::string &message): nickname(std::move(nickname)), std::invalid_argument(message) {}

const std::string &NicknameNotFound::getNickname() const {
    return nickname;
}
