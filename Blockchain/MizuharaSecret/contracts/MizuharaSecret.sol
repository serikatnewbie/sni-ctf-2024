// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract MizuharaSecret {
    bool public solved;

    mapping(uint256 => uint256[]) private secret;

    constructor() {
        secret[1337] = [
            0x456e7669726f6e6d656e74 // REDACTED
        ];
    }

    function getSecret(
        uint256 key,
        uint256 index
    ) public view returns (uint256) {
        require(msg.sender == address(0), "Youre not mizuhara chizuru");
        return secret[key][index];
    }

    function submitSecret(uint256 _secret) public {
        require(_secret == secret[1337][0], "Wrong secret");
        solved = true;
    }
}
