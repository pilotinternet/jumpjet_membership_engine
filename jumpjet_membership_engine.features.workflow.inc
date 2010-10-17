<?php

/**
 * Implementation of hook_workflow_defaults().
 */
function jumpjet_membership_engine_workflow_defaults() {
 $defaults = array();
  $defaults[] = array(
    'name' => 'member approval',
    'machine_name' => 'member_approval',
    'tab_roles' => array(
      '0' => NULL,
      '1' => 'community manager',
      '2' => 'site manager',
      '3' => 'web developer',
    ),
    'options' => array(
      'comment_log_node' => 1,
      'comment_log_tab' => 1,
    ),
    'states' => array(
      '0' => array(
        'state' => '(creation)',
        'weight' => '-50',
        'sysid' => '1',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '0',
        'access' => array(),
      ),
      '1280309138' => array(
        'state' => 'applied',
        'weight' => '0',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309138',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309154' => array(
        'state' => 'referred back',
        'weight' => '1',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309154',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309229' => array(
        'state' => 'declined',
        'weight' => '2',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309229',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309244' => array(
        'state' => 'approved',
        'weight' => '4',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309244',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309261' => array(
        'state' => 'invoiced',
        'weight' => '5',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309261',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309274' => array(
        'state' => 'active',
        'weight' => '6',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309274',
        'access' => array(
          '0' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '1' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '2' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '3' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'community manager',
            'grant_view' => '0',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'site manager',
            'grant_view' => '0',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'web developer',
            'grant_view' => '0',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309441' => array(
        'state' => 'suspended',
        'weight' => '7',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309441',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '1',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
      '1280309420' => array(
        'state' => 'lapsed',
        'weight' => '8',
        'sysid' => '0',
        'status' => '1',
        'module' => 'jumpjet_membership_engine',
        'ref' => '1280309420',
        'access' => array(
          '0' => array(
            'role' => 'community manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '1' => array(
            'role' => 'site manager',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '2' => array(
            'role' => 'web developer',
            'grant_view' => '1',
            'grant_update' => '1',
            'grant_delete' => '1',
          ),
          '3' => array(
            'role' => 'author',
            'rid' => '-1',
            'grant_view' => '1',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '4' => array(
            'role' => 'anonymous user',
            'rid' => '1',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '5' => array(
            'role' => 'authenticated user',
            'rid' => '2',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '6' => array(
            'role' => 'applicant user',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '7' => array(
            'role' => 'approved member',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '8' => array(
            'role' => 'community moderator',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '9' => array(
            'role' => 'content author',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
          '10' => array(
            'role' => 'content editor',
            'grant_view' => '0',
            'grant_update' => '0',
            'grant_delete' => '0',
          ),
        ),
      ),
    ),
    'roles' => array(
      'author' => array(
        'name' => 'author',
        'transitions' => array(
          '0' => array(
            'from' => '0',
            'to' => '1280309138',
          ),
          '1' => array(
            'from' => '1280309154',
            'to' => '1280309138',
          ),
        ),
      ),
      'community manager' => array(
        'name' => 'community manager',
        'transitions' => array(
          '0' => array(
            'from' => '1280309138',
            'to' => '1280309154',
          ),
          '1' => array(
            'from' => '1280309138',
            'to' => '1280309229',
          ),
          '2' => array(
            'from' => '1280309138',
            'to' => '1280309244',
          ),
          '3' => array(
            'from' => '1280309154',
            'to' => '1280309138',
          ),
          '4' => array(
            'from' => '1280309154',
            'to' => '1280309244',
          ),
          '5' => array(
            'from' => '1280309244',
            'to' => '1280309261',
          ),
          '6' => array(
            'from' => '1280309244',
            'to' => '1280309274',
          ),
          '7' => array(
            'from' => '1280309261',
            'to' => '1280309274',
          ),
          '8' => array(
            'from' => '1280309274',
            'to' => '1280309441',
          ),
          '9' => array(
            'from' => '1280309274',
            'to' => '1280309420',
          ),
          '10' => array(
            'from' => '1280309441',
            'to' => '1280309274',
          ),
          '11' => array(
            'from' => '1280309441',
            'to' => '1280309420',
          ),
          '12' => array(
            'from' => '1280309420',
            'to' => '1280309274',
          ),
        ),
      ),
      'site manager' => array(
        'name' => 'site manager',
        'transitions' => array(
          '0' => array(
            'from' => '1280309138',
            'to' => '1280309154',
          ),
          '1' => array(
            'from' => '1280309138',
            'to' => '1280309229',
          ),
          '2' => array(
            'from' => '1280309138',
            'to' => '1280309244',
          ),
          '3' => array(
            'from' => '1280309154',
            'to' => '1280309138',
          ),
          '4' => array(
            'from' => '1280309154',
            'to' => '1280309244',
          ),
          '5' => array(
            'from' => '1280309229',
            'to' => '1280309138',
          ),
          '6' => array(
            'from' => '1280309229',
            'to' => '1280309244',
          ),
          '7' => array(
            'from' => '1280309244',
            'to' => '1280309261',
          ),
          '8' => array(
            'from' => '1280309244',
            'to' => '1280309274',
          ),
          '9' => array(
            'from' => '1280309261',
            'to' => '1280309274',
          ),
          '10' => array(
            'from' => '1280309274',
            'to' => '1280309441',
          ),
          '11' => array(
            'from' => '1280309274',
            'to' => '1280309420',
          ),
          '12' => array(
            'from' => '1280309441',
            'to' => '1280309274',
          ),
          '13' => array(
            'from' => '1280309441',
            'to' => '1280309420',
          ),
          '14' => array(
            'from' => '1280309420',
            'to' => '1280309274',
          ),
        ),
      ),
      'web developer' => array(
        'name' => 'web developer',
        'transitions' => array(
          '0' => array(
            'from' => '1280309138',
            'to' => '1280309154',
          ),
          '1' => array(
            'from' => '1280309138',
            'to' => '1280309229',
          ),
          '2' => array(
            'from' => '1280309138',
            'to' => '1280309244',
          ),
          '3' => array(
            'from' => '1280309154',
            'to' => '1280309138',
          ),
          '4' => array(
            'from' => '1280309154',
            'to' => '1280309244',
          ),
          '5' => array(
            'from' => '1280309229',
            'to' => '1280309138',
          ),
          '6' => array(
            'from' => '1280309229',
            'to' => '1280309244',
          ),
          '7' => array(
            'from' => '1280309244',
            'to' => '1280309261',
          ),
          '8' => array(
            'from' => '1280309244',
            'to' => '1280309274',
          ),
          '9' => array(
            'from' => '1280309261',
            'to' => '1280309274',
          ),
          '10' => array(
            'from' => '1280309274',
            'to' => '1280309441',
          ),
          '11' => array(
            'from' => '1280309274',
            'to' => '1280309420',
          ),
          '12' => array(
            'from' => '1280309441',
            'to' => '1280309274',
          ),
          '13' => array(
            'from' => '1280309441',
            'to' => '1280309420',
          ),
          '14' => array(
            'from' => '1280309420',
            'to' => '1280309274',
          ),
        ),
      ),
    ),
    'types' => array(
      'jumpjet_membership' => 'jumpjet_membership',
    ),
  );
  return $defaults;

}
