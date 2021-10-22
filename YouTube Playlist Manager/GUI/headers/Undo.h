#pragma once
#include "TutorialModel.h"
#include "IFileRepo.h"
class Action {
public:
	Action() {};
	virtual void redo() = 0;
	virtual void undo() = 0;
};


class AddAction : public Action {
public:
	AddAction(IFileRepo* f, Tutorial l) :Action(), repo(f), t(l) {};
	IFileRepo* repo;
	Tutorial t;
	void undo() override {
		repo->removeTutorial(t.getPresenter(),t.getTitle());
	};
	void redo() override {
		repo->addTutorial(t);
	};
};

class RemoveAction : public Action {
public:
	RemoveAction(IFileRepo* f, Tutorial l) :Action(), repo(f), t(l) {};
	IFileRepo* repo;
	Tutorial t;
	void redo() override {
		repo->removeTutorial(t.getPresenter(), t.getTitle());
	};
	void undo() override {
		repo->addTutorial(t);
	};
};

class UpdateAction : public Action {
public:
	UpdateAction(IFileRepo* f, Tutorial old,Tutorial newT) :Action(), repo(f), old(old),newl(newT) {};
	IFileRepo* repo;
	Tutorial old;
	Tutorial newl;
	void redo() override {
		repo->updateTutorial(newl, old.getPresenter(), old.getTitle());
	};
	void undo() override {
		repo->updateTutorial(old, newl.getPresenter(), newl.getTitle());
	};
};