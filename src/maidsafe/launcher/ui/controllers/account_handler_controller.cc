/*  Copyright 2015 MaidSafe.net limited

    This MaidSafe Software is licensed to you under (1) the MaidSafe.net Commercial License,
    version 1.0 or later, or (2) The General Public License (GPL), version 3, depending on which
    licence you accepted on initial access to the Software (the "Licences").

    By contributing code to the MaidSafe Software, or to this project generally, you agree to be
    bound by the terms of the MaidSafe Contributor Agreement, version 1.0, found in the root
    directory of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also
    available at: http://www.maidsafe.net/licenses

    Unless required by applicable law or agreed to in writing, the MaidSafe Software distributed
    under the GPL Licence is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS
    OF ANY KIND, either express or implied.

    See the Licences for the specific language governing permissions and limitations relating to
    use of the MaidSafe Software.                                                                 */

#include "maidsafe/launcher/ui/controllers/account_handler_controller.h"
#include "maidsafe/launcher/ui/helpers/qt_push_headers.h"
#include "maidsafe/launcher/ui/helpers/qt_pop_headers.h"
#include "maidsafe/launcher/ui/helpers/main_window.h"

namespace maidsafe {

namespace launcher {

namespace ui {

namespace controllers {

AccountHandlerController::AccountHandlerController(
    helpers::MainWindow& main_window, QObject* parent)
    : QObject{parent},
      main_window_{main_window} {
  connect(this, SIGNAL(LoginCompleted()), parent, SLOT(LoginCompleted()), Qt::UniqueConnection);
}

AccountHandlerController::AccountHandlingViews AccountHandlerController::currentView() const {
  return current_view_;
}

void AccountHandlerController::setCurrentView(const AccountHandlingViews new_current_view) {
  if (new_current_view != current_view_) {
    current_view_ = new_current_view;
    emit currentViewChanged(current_view_);
  }
}

void AccountHandlerController::login(const QString& pin, const QString& keyword,
                                     const QString& password) {
  (void)pin; (void)keyword; (void)password;
}

void AccountHandlerController::showLoginView() { setCurrentView(LoginView); }

void AccountHandlerController::createAccount(const QString& pin, const QString& keyword,
                                             const QString& password) {
  (void)pin; (void)keyword; (void)password;
}

void AccountHandlerController::showCreateAccountView() { setCurrentView(CreateAccountView); }

void AccountHandlerController::Invoke() {
  main_window_.setWidth(300);
  main_window_.setHeight(400);
  main_window_.CenterToScreen();
  main_window_.show();
}

}  // namespace controllers

}  // namespace ui

}  // namespace launcher

}  // namespace maidsafe