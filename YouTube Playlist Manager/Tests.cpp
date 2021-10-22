//
// Created by Andrei on 4/13/2021.
//

#include "headers/Tests.h"
#include <string>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "headers/IFileRepo.h"
#include "headers/CSVRepo.h"
#include "headers/Controller.h"

void testMain() {
    remove("..//input files//test.txt");
    std::ofstream outfile ("..//input files//test.txt");
    outfile.close();

    testExceptions();
    testFileRepo();
}

void testExceptions() {
    std::string s = "abc";
    std::string p = "123";
    try {
        int n = Validator::strToInt(s);
    }
    catch (ValidationException &v) {
        assert(std::string(v.what()) == "Cannot convert string to int");
    }

    int n = Validator::strToInt(p);
    assert(n == 123);
}

void testFileRepo() {
    IFileRepo *fl = new CSVRepo("..//input files//test.txt");
    IFileRepo *fl2 = new CSVRepo("..//input files//test.txt");
    Tutorial s1{"title", "pres", Duration{1, 2}, 3, "https://www.google.com", 4};
    Controller *c = new Controller(fl, fl2);
    c->addTutorialToRepository(s1);
    c->addTutorialToWatchlist(s1);
    delete c;
}

//
//void test_vector() {
//    DynamicVector<int> d{2};
//
//    //add + getSize
//    d = 2 + d;
//    d = d + 1;
//    d.add(3);
//    d.add(4);
//    d.add(5);
//    assert(d.getSize() == 5);
//
//    //delete + overloading operator []
//    d.deleteElem(1);
//    d.deleteElem(-1);
//    assert(d.getSize() == 4);
//    assert(d[1] == 3);
//    assert(d[0] == 2);
//    d.getAllElems();
//    assert(d[0] == 2);
//}
//
//void test_repo_ctrl_iterator() {
//    Tutorial s1{"F", "D", Duration{3, 38}, 200, "https://www.youtube.com/watch?v=iSZLE9qPN14", 20};
//    assert(s1.getPresenter() == "D");
//    assert(s1.getTitle() == "F");
//    assert(s1.getDuration().getMinutes() == 3);
//    assert(s1.getDuration().getSeconds() == 38);
//    assert(s1.getNoLikes() == 200);
//    assert(s1.getSource() == "https://www.youtube.com/watch?v=iSZLE9qPN14");
//    s1.like();
//    assert(s1.getNoLikes() == 201);
//    s1.open();
//
//    Repository repo{};
//    Tutorial s2{"T", "I", Duration{8, 12}, 200, "https://www.youtube.com/watch?v=iSZLE9qPN14"};
//    Tutorial s3{"S", "E", Duration{3, 47}, 200, "https://www.youtube.com/watch?v=iSZLE9qPN14"};
//
//    assert(s2 < s1.getNoViews());
//    repo.addTutorial(s1);
//    repo.addTutorial(s2);
//    repo.addTutorial(s3);
//
//    // find by title and presenter
//    assert(repo.findByPresenterAndTitle("D", "F").getPresenter() == s1.getPresenter());
//    assert(repo.findByPresenterAndTitle("D", "F").getTitle() == s1.getTitle());
//
//    // find pos of tutorial
//    assert(repo.findPosOfTutorial(s1) == 0);
//    assert(repo.findPosOfTutorial(s2) == 1);
//    assert(repo.findPosOfTutorial(Tutorial{}) == -1);
//
//    // get all
//    DynamicVector<Tutorial> dRepo = repo.getTutorials();
//    assert(dRepo[0].getPresenter() == s1.getPresenter());
//    assert(dRepo[1].getPresenter() == s2.getPresenter());
//    assert(dRepo[2].getPresenter() == s3.getPresenter());
//
//    // remove
//    assert(repo.removeTutorial(s1.getPresenter(), s1.getTitle()));
//    repo.addTutorial(s1);
//
//    // CONTROLLER TESTS
//    Controller ctrl{repo};
//
//    assert(ctrl.getRepo().getTutorials().getSize() == repo.getTutorials().getSize());
//    assert(ctrl.getWatchlist().getTutorials().getSize() == 0);
//
//    // add
//    assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
//    assert(!ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 2, 2, 2, "232"));
//
//    // remove
//    assert(ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
//    assert(!ctrl.removeTutorialFromRepository(s1.getPresenter(), s1.getTitle()));
//
//    // update
//    assert(!ctrl.updateTutorialFromRepository(s2.getPresenter(), s2.getTitle(), 23, 23, 23, "sdfs", s3.getPresenter(),
//                                              s3.getTitle()));
//    assert(ctrl.updateTutorialFromRepository(s3.getPresenter(), s3.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
//    assert(!ctrl.updateTutorialFromRepository(s1.getPresenter(), s1.getTitle(), 23, 23, 23, "sdfs", "test", "update"));
//
//    //add
//    ctrl.addTutorialToWatchlist(s1);
//    ctrl.addTutorialToRepository(s1.getPresenter(), s1.getTitle(), 22, 2, 2, "sdfs");
//    assert(ctrl.getWatchlist().getTutorials().getSize() == 1);
//
//    // ITERATOR TESTS
//    ctrl.configIterator(s1.getTitle());
//    ctrl.startIteration();
//
//    Repository repo2{};
//    repo2.addTutorial(s1);
//    repo2.addTutorial(s2);
//
//    Controller ctrl2{repo2};
//    ctrl.configIterator("");
//    ctrl.startIteration();
//    ctrl2.configIterator(s1.getPresenter());
//    ctrl2.startIteration();
//    assert(ctrl2.getCurrentTutorial().getTitle() == s1.getTitle());
//    assert(!ctrl.deleteTutorialFromWatchlist(s2));
//    ctrl2.next();
//    assert(ctrl.getCurrentTutorial().getPresenter() == s2.getPresenter());
//    ctrl2.likeTutorial();
//    assert(ctrl2.getCurrentTutorial().getNoLikes() == s2.getNoLikes() + 1);
//
//    Iterator iter{};
//    iter.next();
//    assert(iter.getCurrent().getPresenter() == "");
//    iter.add(s1);
//    assert(iter.getCurrent().getPresenter() == s1.getPresenter());
//    iter.emptyIterator();
//    assert(iter.isEmpty());
//}