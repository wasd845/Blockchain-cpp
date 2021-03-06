#include "Blockchain.h"

#include <sstream>
#include <ctime>
#include <iostream>

Block::Block()
{

}

Block::Block(Proof* proof, const std::vector<Transaction*>* transactions, size_t pervious_hash, int index)
{
    this->proof = *proof;
    this->transactions = *transactions;
    this->previous_hash = pervious_hash;
    this->index = index;
    this->timestamp = time(nullptr);
}

Block::Block(size_t index, size_t timestamp, Proof* proof, size_t previous_hash, std::vector<Transaction*> transactions)
: index(index)
, timestamp(timestamp)
, proof(*proof)
, previous_hash(previous_hash)
, transactions(transactions)
{

}

Block::~Block()
{
    
}

const Proof* Block::get_proof() const
{
    return &proof;
}

size_t Block::get_previous_hash() const
{
    return previous_hash;
}

std::string Block::string() const
{
    std::stringstream strstream;
    strstream << "index : " << index << std::endl;
    strstream << "timestamp : " << timestamp << std::endl;
    strstream << "proof : " << proof << std::endl;
    strstream << "previous_hash : " << previous_hash << std::endl;
    strstream << "transaction : " << std::endl;
    for(auto i = 0; i != transactions.size(); i++)
        strstream << "    transaction " << i << " : " << *transactions[i] << std::endl;

    return strstream.str();
}

int Block::get_index() const
{
    return index;
}
