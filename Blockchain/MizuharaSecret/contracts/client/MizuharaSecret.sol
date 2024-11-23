// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract MizuharaSecret {
    bool public solved;

    mapping(uint256 => uint256[]) private secret;

    constructor() {
        secret[1337] = [
            0x5245444143544544 // REDACTED
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
