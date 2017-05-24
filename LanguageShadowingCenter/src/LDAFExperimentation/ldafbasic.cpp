/******************************************************
Author: resat.gafarli@gmail.com
File: ldafbasic
Date: 5/24/2017
License: GPL-3.0
*******************************************************/
#include "ldafbasic.h"

/**/
LDAFBase::LDAFBase(QObject *parent,QPointer<LDAFCommandListProcessor>commandListProcessor):
    QObject(parent),
    m_commandListProcessor(commandListProcessor){
}

void LDAFBase::setReceiverObject(LDAFBase * object){
     m_object = object;
 }
void LDAFBase::addCommand(QUrl url) {
    m_commandListProcessor->addCommand(url,m_object);
 }

void LDAFBase::processForwardByOne(){
     m_commandListProcessor->processBackwardByOne();
}

void LDAFBase::processBackwardByOne(){
    m_commandListProcessor->processBackwardByOne();
}

void LDAFBase::processAllForward(){
    m_commandListProcessor->processAllForward();
}

void LDAFBase::processAllBackward(){
    m_commandListProcessor->processAllBackward();
}


/**/
LDAFMessageType::LDAFMessageType(LDAFBase * basicObject):m_basicObject(basicObject){

}
LDAFMessageType::~LDAFMessageType(){

}

/**/
LDAFUrl::LDAFUrl(QUrl url, LDAFBase * basicObject):
    LDAFMessageType(basicObject),
    m_url(url){

}
LDAFUrl::~LDAFUrl(){

}

void LDAFUrl::setMessage(){
    if (m_basicObject!=nullptr) m_basicObject->setURLMessage(m_url);
}

/**/

LDAFJson::LDAFJson(QJsonObject jsonobject, LDAFBase * basicObject):
    LDAFMessageType(basicObject),
    m_jsonobject(jsonobject){

}
LDAFJson::~LDAFJson(){

}

void LDAFJson::setMessage(){
    if (m_basicObject!=nullptr) m_basicObject->setJsonMessage(m_jsonobject);
}

/**/

LDAFCommand::LDAFCommand(LDAFMessageType * object, Method method):
     m_object(object),
     m_method(method){

}

LDAFCommand::~LDAFCommand(){
     if (m_object != nullptr)
         delete m_object;
 }

void LDAFCommand::executeCommand(){
     if ((m_object!=nullptr)&&(m_method!=nullptr))
         (m_object->*m_method)();
 }

/**/
void LDAFCommandListProcessor::addCommand(QUrl message, LDAFBase * toObject)
{
    addUrlMessage(message,toObject);
}

void LDAFCommandListProcessor::addCommand(QJsonObject message, LDAFBase * toObject)
{
    addJsonObjectMessage(message,toObject);
}

void LDAFCommandListProcessor::processForwardByOne(){
    if (!m_activeQueue.isEmpty()){
        LDAFCommand * command  = m_activeQueue.dequeue();
        command->executeCommand();
        m_processedStack.push(command);
    }
}

void LDAFCommandListProcessor::processBackwardByOne(){
    if (!m_processedStack.isEmpty()){
        LDAFCommand * command  = m_processedStack.top();
        command->executeCommand();
        m_processedStack.pop();
        m_activeQueue.enqueue(command);
    }
}

void LDAFCommandListProcessor::processAllForward(){
    while (!m_activeQueue.isEmpty()){
        processForwardByOne();
    }
}

void LDAFCommandListProcessor::processAllBackward(){
    while (!m_processedStack.isEmpty()){
        processBackwardByOne();
    }
}

void LDAFCommandListProcessor::addUrlMessage(QUrl & message, LDAFBase * toObject){
    m_activeQueue.enqueue(new LDAFCommand(new LDAFUrl(message,toObject), &LDAFMessageType::setMessage));
}

void LDAFCommandListProcessor::addJsonObjectMessage(QJsonObject & message, LDAFBase * toObject){
    m_activeQueue.enqueue(new LDAFCommand(new LDAFJson(message,toObject) ,&LDAFMessageType::setMessage));
}


