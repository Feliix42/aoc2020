#include "questionaire.hpp"

QuestionaireGroup::QuestionaireGroup(int task_number) {
    bool init = false;
    if (task_number == 2) {
        init = true;
    }

    for (int i = 0; i < 26; i++) {
        answers[i] = init;
    }
}

void QuestionaireGroup::clear(int task_number) {
    bool init = false;
    if (task_number == 2) {
        init = true;
    }

    for (int i = 0; i < 26; i++) {
        answers[i] = init;
    }
}

unsigned int QuestionaireGroup::report() {
    unsigned int positive = 0;
    for (int i = 0; i < 26; i++) {
        if (answers[i])
            positive++;
    }

    return positive;
}
