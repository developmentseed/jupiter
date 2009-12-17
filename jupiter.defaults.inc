<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _jupiter_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "spaces" && $api == "spaces") {
    return array("version" => 3);
  }
  else if ($module == "system" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_spaces_presets().
 */
function _jupiter_spaces_presets() {
  $export = array();
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'og_jupiter';
  $spaces_presets->title = 'Jupiter group';
  $spaces_presets->description = 'Public group with enabled features, dashboard configuration.';
  $spaces_presets->space_type = 'og';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_og_selective' => '0',
      'spaces_og_register' => 1,
      'spaces_og_directory' => 1,
      'spaces_og_private' => 0,
      'spaces_preset_og' => 'og_jupiter',
      'spaces_features' => array(
        'atrium_reader' => '1',
        'spaces_blog' => '1',
        'spaces_dashboard' => '1',
      ),
      'designkit_image' => array(
        'logo' => 0,
        'print' => 0,
      ),
      'designkit_color' => array(
        'background' => '#00cc55',
      ),
    ),
    'context' => array(
      'spaces_dashboard' => (object) (array(
         'name' => 'spaces_dashboard',
         'description' => 'Dashboard',
         'tag' => 'Dashboard',
         'conditions' => 
        array (
        ),
         'reactions' => 
        array (
          'block' => 
          array (
            'blocks' => 
            array (
              'views-spaces_blog-block_1' => 
              array (
                'module' => 'views',
                'delta' => 'spaces_blog-block_1',
                'region' => 'content',
                'weight' => 0,
              ),
              'views-spaces_blog_comments-block_1' => 
              array (
                'module' => 'views',
                'delta' => 'spaces_blog_comments-block_1',
                'region' => 'right',
                'weight' => 0,
              ),
            ),
            'layout' => 'sidebar',
          ),
        ),
         'table' => 'context',
         'type' => 'Overridden',
         'export_type' => 3,
      )),
    ),
  );

  $export['og_jupiter'] = $spaces_presets;
  $spaces_presets = new stdClass;
  $spaces_presets->disabled = FALSE; /* Edit this to true to make a default spaces_presets disabled initially */
  $spaces_presets->api_version = 3;
  $spaces_presets->name = 'user_jupiter';
  $spaces_presets->title = 'Jupiter user';
  $spaces_presets->description = 'Simple user space preset for Jupiter demo.';
  $spaces_presets->space_type = 'user';
  $spaces_presets->value = array(
    'variable' => array(
      'spaces_features' => array(
        'spaces_blog' => '1',
        'spaces_dashboard' => '1',
      ),
      'designkit_image' => array(
        'logo' => 0,
        'print' => 0,
      ),
      'designkit_color' => array(
        'background' => '#cc0055',
      ),
    ),
    'context' => array(
      'spaces_dashboard' => (object) (array(
         'name' => 'spaces_dashboard',
         'description' => 'Dashboard',
         'tag' => 'Dashboard',
         'conditions' => 
        array (
        ),
         'reactions' => 
        array (
          'block' => 
          array (
            'blocks' => 
            array (
              'views-spaces_blog-block_1' => 
              array (
                'module' => 'views',
                'delta' => 'spaces_blog-block_1',
                'region' => 'content',
                'weight' => 0,
              ),
              'views-spaces_blog_comments-block_1' => 
              array (
                'module' => 'views',
                'delta' => 'spaces_blog_comments-block_1',
                'region' => 'right',
                'weight' => 0,
              ),
            ),
            'layout' => 'sidebar',
          ),
        ),
         'table' => 'context',
         'type' => 'Overridden',
         'export_type' => 3,
      )),
    ),
  );

  $export['user_jupiter'] = $spaces_presets;
  return $export;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _jupiter_user_default_permissions() {
  $permissions = array();

  // Exported permission: switch users
  $permissions[] = array(
    'name' => 'switch users',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: use admin toolbar
  $permissions[] = array(
    'name' => 'use admin toolbar',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _jupiter_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_toolbar';
  $strongarm->value = array(
    'layout' => 'vertical',
    'position' => 'nw',
    'blocks' => array(
      'spaces_dashboard-editor' => 'spaces_dashboard-editor',
      'admin-create' => 'admin-create',
      'admin-menu' => 'admin-menu',
      'admin-devel' => 'admin-devel',
      'context_ui-editor' => 0,
      'context_ui-devel' => 0,
    ),
  );

  $export['admin_toolbar'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_primary_links_source';
  $strongarm->value = 'features';

  $export['menu_primary_links_source'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_group';
  $strongarm->value = 'group';

  $export['og_content_type_usage_group'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_home_page_view';
  $strongarm->value = '0';

  $export['og_home_page_view'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_footer';
  $strongarm->value = '<a href=\'http://drupal.org/project/spacesdemo\'>Spaces 3 demo</a><br/>
    &copy; 2009 by <a href=\'http://www.developmentseed.org\'>Development Seed</a>';

  $export['site_footer'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'blog';

  $export['site_frontpage'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_features';
  $strongarm->value = array(
    'atrium_reader' => '1',
    'jupiter' => '1',
    'spaces_blog' => '1',
    'spaces_dashboard' => '0',
  );

  $export['spaces_features'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_preset_og';
  $strongarm->value = 'og_jupiter';

  $export['spaces_preset_og'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_preset_user';
  $strongarm->value = 'user_jupiter';

  $export['spaces_preset_user'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_defaults';
  $strongarm->value = array(
    'og' => TRUE,
  );

  $export['views_defaults'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_no_hover_links';
  $strongarm->value = 1;

  $export['views_no_hover_links'] = $strongarm;
  return $export;
}
