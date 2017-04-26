/******************************************************
Author: resat.gafarli@gmail.com
File: tst_example_mediator_isolation.h
Date: 4/26/2017
License: GPL-3.0
*******************************************************/
#include <QObject>
#include <QDebug>


class IComponentNameMediator{
public:

    virtual void fromUItoController()=0;
    virtual void fromControllertoEntity()=0;
    virtual void fromEntityTotoController()=0;
    virtual void fromControllerTotoUI()=0;

};

class IComponentNameColleague{
protected:
    explicit IComponentNameColleague(IComponentNameMediator * _mediator):mediator(_mediator){

    }
    IComponentNameMediator * mediator;
};


class UIClass : public QObject, public IComponentNameColleague
{
public:
    UIClass(IComponentNameMediator * _mediator):
        QObject(),IComponentNameColleague(_mediator){

    }
    void sayHelloUI(){
        qDebug()<<"sayHelloUI"<<endl;
        mediator->fromUItoController();
    }


    void sayGoodByUI(){
        qDebug()<<"sayGoodByUI"<<endl;
    }

};

class ControllerClass : public IComponentNameColleague
{
public:
    ControllerClass(IComponentNameMediator * _mediator):IComponentNameColleague(_mediator){
    }

    void sayHelloController(){
        qDebug()<<"sayHelloController"<<endl;
        mediator->fromControllertoEntity();
    }

    void sayGoodByController(){
        qDebug()<<"sayGoodByController"<<endl;
        mediator->fromControllerTotoUI();
    }

};


class EntityClass : public IComponentNameColleague
{
public:
    EntityClass(IComponentNameMediator * _mediator):IComponentNameColleague(_mediator){

    }

    void sayHelloEntity(){
        qDebug()<<"sayHelloEntity"<<endl;
        qDebug()<<"sayGoodByEntity"<<endl;
        mediator->fromEntityTotoController();
    }

};
/*
 * All classes test example
*/

class tst_TestMediatorClass: public QObject, public IComponentNameMediator
{
    Q_OBJECT

public:
    UIClass * uiClass;
    ControllerClass * controlClass;
    EntityClass  * entityClass;

    tst_TestMediatorClass(){}

    void fromUItoController(){
        controlClass->sayHelloController();
    }

    void fromControllertoEntity(){
        entityClass->sayHelloEntity();
    }

    void fromEntityTotoController(){
        controlClass->sayGoodByController();
    }

    void fromControllerTotoUI(){
        uiClass->sayGoodByUI();
    }

private Q_SLOTS:

    void testCase1()
    {   //All classes are instantiated and integrated over this medidator.
        uiClass = new UIClass(this);
        controlClass = new ControllerClass(this);
        entityClass = new EntityClass(this);
        uiClass->sayHelloUI();
    }
};

/*
 * Isolated ControlClass class test example
*/
class tst_TestMediatorControlClass: public QObject, public IComponentNameMediator
{
    Q_OBJECT

public:
    ControllerClass * controlClass;
    tst_TestMediatorControlClass(){}

    void fromUItoController(){

    }

    void fromControllertoEntity(){
        qDebug()<<"sayHelloEntity"<<endl;
        qDebug()<<"sayGoodByEntity"<<endl;
    }

    void fromEntityTotoController(){

    }

    void fromControllerTotoUI(){

    }

private Q_SLOTS:

    void testCase1()
    {
        //Control class is instantiated and integrated to this medidator
        controlClass = new ControllerClass(this);
        controlClass->sayHelloController();
        controlClass->sayGoodByController();
    }

};

