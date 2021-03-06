/*
 * Copyright 2016-2017 Flatiron Institute, Simons Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef INDIVIDUALMERGEDECISIONPAGE_H
#define INDIVIDUALMERGEDECISIONPAGE_H

#include <QWizard>
#include <mvcontext.h>
#include <mvmainwindow.h>

class IndividualMergeDecisionPagePrivate;
class IndividualMergeDecisionPage : public QWizardPage {
    Q_OBJECT
public:
    friend class IndividualMergeDecisionPagePrivate;
    IndividualMergeDecisionPage(MVContext* context, MVMainWindow* mw);
    virtual ~IndividualMergeDecisionPage();
private slots:
    void slot_goto_previous_pair();
    void slot_goto_next_pair();
    void slot_button_clicked();
    void slot_add_merge_candidate_tag();
    void slot_remove_merge_candidate_tag();
    void slot_add_mua_and_reject_tags();
    void slot_update_candidates();

private:
    IndividualMergeDecisionPagePrivate* d;
};

#endif // INDIVIDUALMERGEDECISIONPAGE_H
