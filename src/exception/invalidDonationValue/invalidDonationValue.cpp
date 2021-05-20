//
// Created by nrtc on 26/12/2020.
//

#include "invalidDonationValue.h"

float InvalidDonationValue::getValue() const {
    return value;
}

InvalidDonationValue::InvalidDonationValue(float value, const std::string &message) : std::invalid_argument(message), value(value){}
