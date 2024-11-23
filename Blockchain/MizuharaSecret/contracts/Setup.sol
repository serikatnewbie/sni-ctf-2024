// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

import "./MizuharaSecret.sol";

contract Setup {
    MizuharaSecret public mizuharaSecret;

    constructor() payable {
        mizuharaSecret = new MizuharaSecret();
    }

    function isSolved() public view returns (bool) {
        return mizuharaSecret.solved() == true;
    }
}
