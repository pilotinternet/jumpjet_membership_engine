<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jumpjet_membership_engine_user_default_permissions() {
  $permissions = array();

  // Exported permission: access workflow summary views
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      '0' => 'community manager',
      '1' => 'web developer',
      '2' => 'site manager',
    ),
  );

  // Exported permission: administer role expire
  $permissions['administer role expire'] = array(
    'name' => 'administer role expire',
    'roles' => array(
      '0' => 'community manager',
      '1' => 'web developer',
      '2' => 'site manager',
    ),
  );

  // Exported permission: administer rules
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      '0' => 'web developer',
    ),
  );

  // Exported permission: administer workflow
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      '0' => 'web developer',
    ),
  );

  // Exported permission: schedule workflow transitions
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      '0' => 'community manager',
      '1' => 'web developer',
      '2' => 'site manager',
    ),
  );

  return $permissions;
}
