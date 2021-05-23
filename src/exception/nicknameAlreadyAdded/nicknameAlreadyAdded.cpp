//
// Created by Danny on 18/11/2020.
//

#include "nicknameAlreadyAdded.h"

NicknameAlreadyAdded::NicknameAlreadyAdded(std::string nickname, const std::string & message): nickname(std::move(nickname)), std::invalid_argument(message) {}

const std::string &NicknameAlreadyAdded::getNickname() const {
    return nickname;
}
