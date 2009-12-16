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
                'region' => 'left',
                'weight' => 0,
              ),
            ),
            'layout' => 'offset',
          ),
        ),
         'table' => 'context',
         'type' => 'Overridden',
         'export_type' => 3,
      )),
    ),
  );

  $export['og_jupiter'] = $spaces_presets;
  return $export;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _jupiter_strongarm() {
  $export = array();
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
  $strongarm->name = 'spaces_preset_og';
  $strongarm->value = 'og_jupiter';

  $export['spaces_preset_og'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'spaces_preset_user';
  $strongarm->value = 'user_jupiter';

  $export['spaces_preset_user'] = $strongarm;
  return $export;
}
