<?php

/**
 * Implementation of hook_strongarm().
 */
function jumpjet_membership_engine_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_jumpjet_membership';
  $strongarm->value = 0;

  $export['comment_anonymous_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_jumpjet_membership';
  $strongarm->value = '3';

  $export['comment_controls_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_jumpjet_membership';
  $strongarm->value = '4';

  $export['comment_default_mode_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_jumpjet_membership';
  $strongarm->value = '1';

  $export['comment_default_order_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_jumpjet_membership';
  $strongarm->value = '50';

  $export['comment_default_per_page_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_jumpjet_membership';
  $strongarm->value = '0';

  $export['comment_form_location_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_jumpjet_membership';
  $strongarm->value = '0';

  $export['comment_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_jumpjet_membership';
  $strongarm->value = '1';

  $export['comment_preview_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_jumpjet_membership';
  $strongarm->value = '1';

  $export['comment_subject_field_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_jumpjet_membership';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '0',
    'author' => '20',
    'options' => '25',
    'comment_settings' => '2',
    'menu' => '-2',
    'path' => '1',
    'workflow' => '-1',
  );

  $export['content_extra_weights_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_jumpjet_membership';
  $strongarm->value = array(
    'weight' => '0',
    'user_display' => 'link',
    'edit_link' => 1,
    'edit_tab' => 'sub',
    'add_link' => 1,
    'values' => array(
      0 => 2,
      1 => 3,
      2 => 5,
      3 => 8,
      4 => 6,
      5 => 9,
      6 => 4,
      7 => 7,
    ),
    'registration_use' => 0,
    'admin_user_create_use' => 0,
    'registration_hide' => array(),
    'autoassignrole_use' => array(
      0 => 9,
    ),
  );

  $export['content_profile_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_profile_use_jumpjet_membership';
  $strongarm->value = 1;

  $export['content_profile_use_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_jumpjet_membership';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_jumpjet_membership'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_jumpjet_membership';
  $strongarm->value = array(
    0 => 'node',
  );

  $export['workflow_jumpjet_membership'] = $strongarm;
  return $export;
}
