#pragma once
#include <iostream>
#include <memory>
#include <cassert>
#include <stdexcept>

template<class T>
class GenListNode;

template<class T>
class GenList;

template <class T>
class GenListNode {
    friend class GenList<T>;

    enum class NodeType {
        SentinelType, // 0
        DataType,     // 1
        LinkType      // 2
    };

    union InfoUnion {
        int refCount;        // SentinelType
        T data;              // DataType
        GenListNode<T>* subLink;  // LinkType

        ~InfoUnion() {
            // If additional cleanup is needed, handle it here.
            // For example, if you have custom cleanup logic for 'subLink'.
            // because of the shared_ptr
        }
    };

private:
    NodeType ntype;
    InfoUnion info;
    GenListNode<T>* nextLink;

public:
    GenListNode() : ntype(NodeType::SentinelType), nextLink(nullptr), info{} {}

    // Destructor
    ~GenListNode() {
        if (ntype == NodeType::DataType) {
            // Release resources if DataType is being managed manually
            // For example, if T is a pointer type, you may need to delete it.
        }
    }

    GenListNode(const GenListNode& rhs) = default;

    GenListNode& operator=(const GenListNode& rhs) = default;

    // Move Constructor
    GenListNode(GenListNode&& rhs) noexcept
        : ntype(std::exchange(rhs.ntype, NodeType::SentinelType)),
        info(std::exchange(rhs.info, InfoUnion{})),
        nextLink(std::exchange(rhs.nextLink, nullptr)) {}

    // Move Assignment Operator
    GenListNode& operator=(GenListNode&& rhs) noexcept {
        if (this != &rhs) {
            // Implement appropriate logic for DataType and ListType
            // Release existing resources and move data or shared_ptr as needed
            // Update nextLink
        }
        return *this;
    }

};


template<class T>
class GenList {
private:
    GenListNode<T>* head;
public:
    GenList() {
        head = new GenListNode<T>();   // returns a sentinel type node
        assert(head);
    }
    ~GenList() = default;

    GenListNode<T>& front() const {
        if (head->nextLink == nullptr) {
            std::cerr << "Attempt to access front of an empty list" << std::endl;
            exit(EXIT_FAILURE);
        }
        GenListNode<T>* p2first = head->nextLink;
        GenListNode<T>* result = new GenListNode<T>(*p2first);
        return *result;
    }


};