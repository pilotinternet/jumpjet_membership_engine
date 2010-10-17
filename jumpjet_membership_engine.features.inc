<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jumpjet_membership_engine_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function jumpjet_membership_engine_node_info() {
  $items = array(
    'jumpjet_membership' => array(
      'name' => t('Membership'),
      'module' => 'features',
      'description' => t('Use membership to create a basic user membership profile'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function jumpjet_membership_engine_rules_defaults() {
  return array(
    'rules' => array(
      'jumpjet_membership_engine_1' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'membership application initiated',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                '1' => '1',
              ),
              'to_state' => array(
                '2' => '2',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from (creation) to pending',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 5,
              ),
              'from' => '',
              'subject' => 'new user application',
              'message' => '[author:user] has filled out a membership application

You can view and edit the user at [author:site-url]/[author:account-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'author',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_2' => array(
        '#type' => 'rule',
        '#set' => 'event_user_login',
        '#label' => 'Non-approved member logs in',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'User has role(s)',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_condition_user_hasrole',
            '#settings' => array(
              'roles' => array(
                '0' => 10,
              ),
              'operation' => 'OR',
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'path' => '',
              'query' => 'user',
              'fragment' => '',
              'force' => 1,
              'immediate' => 0,
            ),
            '#name' => 'rules_action_drupal_goto',
            '#info' => array(
              'label' => 'Send to own user page',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Your membership application is currently being processed. You can view the current status using the \'Membership\' link below. Note that if you have an edit link beside your membership link that indicates we are waiting for a response from you.',
              'error' => 0,
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_3' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'membership application referred back',
        '#active' => 1,
        '#weight' => '1',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '0' => array(
              '#type' => 'condition',
              '#settings' => array(
                'from_state' => array(
                  '2' => '2',
                ),
                'to_state' => array(
                  '3' => '3',
                ),
                '#argument map' => array(
                  'old_state' => 'old_state',
                  'new_state' => 'new_state',
                ),
              ),
              '#name' => 'workflow_check_transition',
              '#info' => array(
                'label' => 'Check workflow transition from applied to referred back',
                'arguments' => array(
                  'old_state' => array(
                    'type' => 'workflow_state',
                    'label' => 'Old workflow state',
                  ),
                  'new_state' => array(
                    'type' => 'workflow_state',
                    'label' => 'New workflow state',
                  ),
                ),
                'module' => 'Workflow',
              ),
              '#weight' => 0,
            ),
            '#type' => 'OR',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => '',
              'subject' => 'Membership application query: [new_state:site-name]',
              'message' => 'Hi [author:user]
You recently submitted an application for membership. We require some further information before this can be approved

You can view any issues and respond here: [author:site-url]/node/[node:nid]/workflow

and what about content update tokens such as [node:workflow-current-state-log-entry]',
              '#argument map' => array(
                'user' => 'author',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'new_state',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_4' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Application declined',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check workflow transition from Any state to declined',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_transition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '4' => '4',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => '',
              'subject' => 'Membership application for [author:site-url] declined',
              'message' => '[Hi author:user]
Unfortunately you\'re application to become a member has been declined.',
              '#argument map' => array(
                'user' => 'author',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_5' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Membership application activated',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '7' => '7',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from Any state to active',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Organic groups',
              'arguments' => array(
                'user' => array(
                  'label' => 'User',
                  'type' => 'user',
                ),
              ),
              'label' => 'Subscribe user to the specified groups',
              'base' => 'rules_core_action_execute',
              'action_name' => 'og_subscribe_user_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_og_subscribe_user_action',
            '#settings' => array(
              'groups' => array(
                '2' => '2',
              ),
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 8,
              ),
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#name' => 'rules_action_user_addrole',
            '#info' => array(
              'label' => 'Add user role',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => '',
              'subject' => 'Membership activated',
              'message' => 'Hi,
Your membership account has now been fully activated giving you access to the website membership area. You can login here: [author:site-url]/user',
              '#argument map' => array(
                'user' => 'author',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Inform member of membership activation',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 10,
              ),
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#name' => 'rules_action_user_removerole',
            '#info' => array(
              'label' => 'Remove applicant role assigned by toboggan',
              'label callback' => FALSE,
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
          ),
          '4' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Add expire time to role',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'The user which the expiration time will be added',
                ),
              ),
              'eval input' => array(
                '0' => 'timestamp',
              ),
              'module' => 'Role expire',
            ),
            '#name' => 'role_expire_rules_action_set_role_expire',
            '#settings' => array(
              'rid' => '8',
              'timestamp' => '365 days',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_6' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Membership suspended',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check workflow transition from Any state to suspended',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_transition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '9' => '9',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'action',
            '#settings' => array(
              'roles' => array(
                '0' => 9,
              ),
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#name' => 'rules_action_user_removerole',
            '#info' => array(
              'label' => 'Remove user role',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'groups' => array(
                '30' => '30',
              ),
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#name' => 'rules_core_og_unsubscribe_user_action',
            '#info' => array(
              'module' => 'Organic groups',
              'arguments' => array(
                'user' => array(
                  'label' => 'User',
                  'type' => 'user',
                ),
              ),
              'label' => 'Unsubscribe user from the specified groups',
              'base' => 'rules_core_action_execute',
              'action_name' => 'og_unsubscribe_user_action',
              'configurable' => TRUE,
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_7' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Membership re-applied',
        '#active' => 1,
        '#weight' => '1',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                '3' => '3',
                '8' => '8',
                '9' => '9',
              ),
              'to_state' => array(
                '2' => '2',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from referred back, suspended, lapsed to applied',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 3,
                '1' => 4,
              ),
              'from' => '',
              'subject' => 'Membership application follow-up',
              'message' => 'There has been a membership follow-up.
The applicant made the following comment: [node:workflow-current-state-log-entry]
You can update this membership at http://[node:site-url]/node/[node:nid]/workflow',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_8' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Membership approved',
        '#active' => 1,
        '#weight' => '3',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check workflow transition from Any state to approved',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_transition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                '5' => '5',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => 'Membership provisionally approved',
              'message' => 'Your membership application has been approved and a message has been sent to our accounts department. You will now receive an invoice and when that has been settled, your membership will be activated.',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'to' => 'steve+accounts@artimedia.co.uk',
              'from' => '',
              'subject' => 'User account approved',
              'message' => 'New member approved. Please generate an invoice for this user so that we can activate the membership: [author:site-url]/[author:account-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'author',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_mail',
            '#info' => array(
              'label' => 'Send a mail to a accounts department',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'jumpjet_membership_engine_9' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Log user workflow status',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'membership',
          'jumpjet_membership_engine' => 'jumpjet_membership_engine',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                'ANY' => 'ANY',
              ),
              'to_state' => array(
                'ANY' => 'ANY',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from Any state to Any state',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Execute custom PHP code',
              'module' => 'PHP',
              'eval input' => array(
                '0' => 'code',
              ),
            ),
            '#name' => 'rules_action_custom_php',
            '#settings' => array(
              'code' => '<?php
$state = array(\'current_state\' =>$new_state);
user_save($author,$state);
?>
',
              'vars' => array(
                '0' => 'new_state',
                '1' => 'author',
              ),
              '#eval input' => array(
                'rules_input_evaluator_php' => array(
                  'code' => array(
                    '0' => 'new_state',
                    '1' => 'author',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function jumpjet_membership_engine_views_api() {
  return array(
    'api' => '3.0-alpha1',
  );
}
