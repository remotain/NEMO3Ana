#ifndef Group_h
#define Group_h

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TString.h"
#include "TList.h"
#include "Component.h"

class Group : public Component {

public:
	
	Group(
		const TString &name,
		const TString &title 
		) : Component(name, title) {
		
			Info("Group()","New group %s", GetName());
				
			_ComponentList = new TList();
			
		};

	~Group() { };
			
	void AddComponent( Component * c) { 
		//Info("AddComponent()", "%s , %s", c->GetName(), h->GetName());
		_ComponentList->Add(c);
	};
	
	TList * GetComponentList(){ return _ComponentList; };		
	Component * FindComponent(const char * name) { return (Component *) _ComponentList->FindObject(name); };
			
private:

	TList * _ComponentList;

ClassDef(Group, 1);

};

#endif