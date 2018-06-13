<?php

/**
 * @file
 * Provide views data for redirect_404.module.
 */

/**
 * Implements hook_views_data().
 */
function term_list_user_views_data() {
  $data = [];

  $data['user__list_used_term'] = [];
  $data['user__list_used_term']['table'] = [];

  $data['user__list_used_term']['table']['group'] = t('Term User Used');

  $data['user__list_used_term']['table']['base'] = [
    'field' => '',
    'title' => t('Term user used'),
    'help' => t('A list of term used by user.'),
  ];

  $data['user__list_used_term']['table']['join'] = [
    'taxonomy_term_field_data' => [
      'left_field' => 'tid',
      'field' => 'tid',
    ],
  ];

  $data['user__list_used_term']['table']['join'] = [
    'users_field_data' => [
      'left_field' => 'uid',
      'field' => 'uid',
    ],
  ];

  $data['user__list_used_term']['tid'] = [
    'title' => t('Tid'),
    'help' => t('The term id'),
    'relationship' => [
      'base' => 'taxonomy_term_field_data',
      'id' => 'standard',
      'label' => t('Term Information'),
    ],
  ];

  $data['user__list_used_term']['uid'] = [
    'title' => t('Uid'),
    'help' => t('The uid of the user'),
    'relationship' => [
      'base' => 'users_field_data',
      'id' => 'standard',
      'label' => t('User Information'),
    ],
  ];

  $data['user__list_used_term']['langcode'] = [
    'title' => t('Language'),
    'help' => t('The language of this request.'),
    'field' => [
      'id' => 'term_used_langcode',
    ],
    'filter' => [
      'id' => 'language',
    ],
  ];

  $data['user__list_used_term']['vid'] = [
    'title' => t('Vid'),
    'help' => t('The vocabulary id.'),
    'field' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'type',
    ],
  ];

  $data['user__list_used_term']['count'] = [
    'title' => t('count'),
    'help' => t('The used count of the term.'),
    'field' => [
      'id' => 'standard',
    ],
    'sort' => [
      'id' => 'numeric',
    ],
  ];

  $data['user__list_used_term']['term_used_operations'] = [
    'title' => t('Operations'),
    'help' => t('Provide operation buttons to handle the term user used.'),
    'field' => [
      'id' => 'term_used_operations',
      'additional fields' => ['uid', 'langcode'],
      'real field' => 'uid',
    ],
  ];

  return $data;
}


// /**
//  * Implements hook_views_data_alter().
//  */
// function term_list_user_views_data_alter(array &$data) {
//   $data['users_field_data']['term_list'] = [
//     'title' => t("Les terms utilisés par l'utilisateur"),
//     'help' => t("Permet de relier les term des node à l'utilisateur qui les utilises"),
//     'relationship' => [
//       'group' => t('Terms list'),
//       'label' => t("Les terms de l'utilisateur"),
//       'base' => 'user__list_used_term', // nom de la table stockant nos entités custom
//       'base field' => 'uid', // nom du champ sur lequel faire la jointure
//       'relationship field' => 'uid', // nom du champ cible sur lequel faire la jointure (de la table users_field_data)
//       'id' => 'standard',
//     ],
//   ];
// }