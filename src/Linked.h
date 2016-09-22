#ifndef _LINKED_H_
#define _LINKED_H_

#include<vector>

class ForwardLink {
    private:
        ForwardLink *forwardLink;
    public:
        virtual ~ForwardLink();
        virtual ForwardLink *getNext() {return this->forwardLink;};
        virtual void setNext(ForwardLink *newForwardLink) {this->forwardLink = newForwardLink;};
};

class BackwardLink {
    private:
        BackwardLink *backwardLink;
    public:
        virtual ~BackwardLink();
        virtual BackwardLink *getPrev() {return this->backwardLink;};
        virtual void setPrev(BackwardLink *newBackwardLink) {this->backwardLink = newBackwardLink;};
};

class NForwardLinks {
    private:
        std::vector<ForwardLink*> forwardLinks;
    public:
        virtual ~NForwardLinks();
        virtual std::vector<ForwardLink*> *getForwardLinks() {return &(this->forwardLinks);};
        virtual void addLink(ForwardLink *forwardLink) {this->forwardLinks.push_back(forwardLink);};
};
#endif
