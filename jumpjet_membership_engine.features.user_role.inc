<?php

/**
 * Implementation of hook_user_default_roles().
 */
function jumpjet_membership_engine_user_default_roles() {
  $roles = array();

  // Exported role: approved member
  $roles['approved member'] = array(
    'name' => 'approved member',
  );

  return $roles;
}
