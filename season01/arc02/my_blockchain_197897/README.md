# Welcome to My Blockchain
***

## Task
The core objective of this project is to implement a Command-Line Interface (CLI) tool that simulates the basic operations of a decentralized blockchain system.

The main challenge lies in managing and manipulating two interconnected dynamic data structures:

A linked list of nodes (representing different participants/servers).

A linked list of blocks within each node (representing the individual chains).

We must ensure persistence by saving and loading the state of the entire network to a backup file (blockchain.bak). Additionally, the CLI must handle complex operations like synchronization (sync) and maintain a custom, state-based prompt system (e.g., [s1]>, [-3]>).

## Description
This project solves the challenge by utilizing standard C (C99) and dynamic memory allocation to build and manage the data structures.

Key Implementation Details:
Data Structures: The network is managed using two structures: t_node (for decentralized peers) and t_block (for data blocks), both implemented as singly linked lists.

Prompt Logic: A global command counter (g_command_count) dictates the shell's prompt state ([s0] through [s3], or specialized states like [-2] and [-3]), reflecting the current complexity or phase of the simulated network.

Synchronization (sync): The sync command identifies all unique blocks across all active nodes, creates a master list, and then distributes the missing blocks to every node in the network, maintaining the correct FIFO (First-In, First-Out) insertion order required for blockchain integrity.

Persistence: The network state is saved to and loaded from blockchain.bak using file system operations (open, read, dprintf, getline).

## Installation
This project is built using a standard C compiler (like GCC or Clang) and typically requires a Makefile.

Clone the repository:

Bash

git clone [Your Repository URL]
cd my_blockchain
Compile the project:

Bash

make
# If the Makefile includes a re-compilation rule:
# make re 
This will generate the executable file, usually named ./my_blockchain.

## Usage
The program runs as an interactive shell.Start the CLI:Bash./my_blockchain
The shell will start with the initial prompt: [s0]>Available Commands:CommandArgumentsDescriptionadd node<node_id>Adds a new node to the network.add block<block_id> <target_node_id>Adds a block to the specified node. Supports * as target_node_id to add to all nodes.rm node<node_id>Removes a node from the network, freeing its associated blocks.rm block<block_id> <target_node_id>Removes a block from the specified node. Supports * as target_node_id.ls(Optional: -l)Lists all active nodes. Use -l for detailed list, showing blocks per node (<node_id>: <block1>, <block2>).sync(None)Synchronizes all blocks across the entire network.quit(None)Saves the current state to blockchain.bak and exits.Example Session[s0]>add node 12
OK
[s1]>add block 21 12
OK
[s1]>ls -l
12: 21
[s1]>add node 15
OK
[s2]>add block 22 15
OK
[s3]>ls -l
12: 21
15: 22
[s3]>sync
OK
[s3]>ls -l
12: 21, 22
15: 22, 21
[s3]>quit

### The Core Team
KENDA NANA BAUDOIN

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
