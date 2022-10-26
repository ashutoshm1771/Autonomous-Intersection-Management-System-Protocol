/*
 * aims.cc
 *
 *  Created on: Oct 26, 2022
 *      Author: Protocol_Pros
 */

#include<string.h>
#include<omnetpp.h>

using namespace omnetpp;

class Core_Processor: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class Message_Processor: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class Video_Processor: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class OCR_Module: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class Request_Receptor_Module: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class Agent_with_IoT_Module: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

class Smart_City_Management_System: public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

Define_Module(Core_Processor);
Define_Module(Message_Processor);
Define_Module(Video_Processor);
Define_Module(OCR_Module);
Define_Module(Request_Receptor_Module);
Define_Module(Agent_with_IoT_Module);
Define_Module(Smart_City_Management_System);


// Core Processor
void Core_Processor::initialize()
{
    if (strcmp("Core", getName()) == 0) {
        cMessage *msg = new cMessage("Core to Message");
        send(msg, "output_gate_message");

        cMessage *msg2 = new cMessage("Core to Smart!!");
        send(msg2, "output_gate_smart_city");
    }
}

void Core_Processor::handleMessage(cMessage *msg)
{
    if (strcmp("Core", getName()) == 0) {
        send(msg, "output_gate_message");
    }
}

// Message_Processor
void Message_Processor::initialize()
{
    if (strcmp("Message", getName()) == 0) {
        cMessage *msg = new cMessage("Message to Core");
        send(msg, "output_gate_core");

        cMessage *msg_to_agent = new cMessage("Message to Agent");
        send(msg_to_agent, "output_gate_agent");
    }
}

void Message_Processor::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_core");
}

// Video_Processor
void Video_Processor::initialize()
{
    if (strcmp("VideoProcessor", getName()) == 0) {
        cMessage *msg = new cMessage("Video to OCR");

        send(msg, "output_gate_ocr");
    }
}

void Video_Processor::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_ocr");
}

// OCR_Module
void OCR_Module::initialize()
{
    if (strcmp("OCRModule", getName()) == 0) {
        cMessage *msg = new cMessage("OCR to Core");
        send(msg, "output_gate_core");
    }
}

void OCR_Module::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_video");
}

// Request_Receptor_Module
void Request_Receptor_Module::initialize()
{
    if (strcmp("Request_Receptor", getName()) == 0) {
        cMessage *msg = new cMessage("Request to Core");
        send(msg, "output_gate_core");
    }
}

void Request_Receptor_Module::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_core");
}

// Agent_with_IoT
void Agent_with_IoT_Module::initialize()
{
    if (strcmp("Agent_with_IoT", getName()) == 0) {
        cMessage *msg = new cMessage("Agent to Request");
        send(msg, "output_gate_request");
    }
}

void Agent_with_IoT_Module::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_message");
}

// Smart_City_Management_System
void Smart_City_Management_System::initialize()
{
    if (strcmp("SmartCity", getName()) == 0) {
        cMessage *msg = new cMessage("Smart to Core");
        send(msg, "output_gate_core");
    }
}

void Smart_City_Management_System::handleMessage(cMessage *msg)
{
    send(msg, "output_gate_core");
}


